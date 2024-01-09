#! /bin/bash

CMAKE_CMD="cmake"
CMAKE_SRC_DIR="$(dirname $0)"

CMAKE_BUILD_TYPE="Debug"

CMAKE_CONIFG_ARGS=

CMAKE_GENERATE_CMD="-G"

CMAKE_BUILD_CMD="-B"

CMAKE_GENERATOR="Unix\ Makefiles"

if [ -e "${CMAKE_SRC_DIR}/configConfigure.sh" ]; then
     . "${CMAKE_SRC_DIR}/configConfigure.sh"
  else
         echo "No config configuration found"
 fi

quote()
 {
     echo "$1" | sed -e "s|'|'\\\\''|g; 1s/^/'/; \$s/\$/'/"
 }

extractCMakeConfig()
{
     VAR_NAME=$1

    if [ "x$2" != "x" ]; then
       VAR_CON_NAME=$2
        else
         echo "No config name found assuming name given by config"
          VAR_CON_NAME=$(echo "$1" | tr '[:lower:]' '[:upper:]' | tr -c '[:alnum:]' '_' | sed 's/_$//g')
     fi

      if [ "x$3" != "x" ]; then
        VAR_VALUE=$3
      else
        echo "No value found assuming true"
         VAR_VALUE=TRUE
      fi
}

setConfigVar()
{
    is_with=n
     case "$1" in
       "--enable-"*)
      name="${1#--enable-}"
         cfg="${ENABLE_VARS}"
             ;;
        "--disable-"*)
          name="${1#--disable-}"
            cfg="${DISABLE_VARS}"
             ;;
        "--with-"*)
           is_with=y;;

    esac

       # inFunc="in"
       #  for ifunc in $inFunc; do
       #      if [ "x${name}" =  "xNO_OPTION' ]; then
       #            echo "${name}"
       #         break;
       #     fi 

      found=n
       for varString in $cfg; do
         extractCMakeConfig $(echo "${varString}" | tr '|' ' ')
          if [ "x${name}" = "x${VAR_NAME}" ]; then
            found=y
             break;
         else if [ "x${name}" = "xNO_OPTION" ]; then
            found=nop
             break;
              fi
            fi
      done

        if [ "${found}" = "y" ]; then
          if [ "x${is_with}" = "xy" ]; then
 CMAKE_CONFIG_ARGS="$CMAKE_CONFIG_ARGS -D${VAR_CON_NAME}=$(quote "$2")"
         else
   CMAKE_CONFIG_ARGS="$CMAKE_CONFIG_ARGS -D${VAR_CON_NAME}=$(quote ${VAR_VALUE})"
            fi
        else if [ "${found}" = "nop" ]; then
          name="no_option_set"
            else
           echo "Unknwon Parameter ${1}"
            exit -1
     fi
  fi
}


printHelp()
{
    cat << EOF
    -h, help              Prints help menu

    --enable-             Enables cmake varible
    --disable-            The same as [enable]
    
    --release-build       Cmake release build
EOF

 exit 0
}

while [ $# != 0 ]; do
  case "$1" in
    "--help")
      printHelp
      ;;
    "-h")
      printHelp
      ;;
    "--release-build")
      CMAKE_BUILD_TYPE="Release"
       ;;
    "--enable-"*)
      setConfigVar "$1"
      ;;
    "--disable-"*)
      setConfigVar "$1"
      ;;
    "--with-"*)
      name=$(echo "${1#--with-}")
       case "${1}" in 
        "--with-${name}="*)
           setConfigVar "--with-${name}" "${1#--with-${name}=}"
           ;;
         "--with-${name}")
             setConfigVar "$1" "$2";
               shift
               ;;
            esac
            ;;
  *)
   echo "Error: Unkown option: \'$1'"
    echo "Try \'$0' --help' for more information"
     exit -1

      esac
  shift
 done
 
cd ../

eval "${CMAKE_CMD}" \
     "${CMAKE_SRC_DIR}" \
     "${CMAKE_GENERATE_CMD}" "${CMAKE_GENERATOR}" \
     "${CMAKE_CONFIG_ARGS}" \
      -DCMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}" \
      "${CMAKE_BUILD_CMD}" \ build/debug
