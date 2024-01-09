#! /bin/bash

#Cofig options:
#
#no_log
#warning_as_errors




for enable in \
    warning_as_errors \
    NO_OPTION; do
    CENABLE_VARS="${CENABLE_VARS} --enable-${enable}"
done

for disable in \
    no_log \
    NO_OPTION; do
  CDISABLE_VARS="${CDISABLE_VARS} --disable-${disable}"
done

CVAR="${CENABLE_VARS} ${CDISABLE_VARS}"

./configure.sh ${CVAR}
