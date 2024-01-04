*The value of a concept is always bool.
*The arguments of a template is checked against its concept at point of use, what cannot be checked(such as unconstrainted templetes) 
are postponed until code is generated or the template with a set of template arguments.
*A string-view is a readoonly view of its characters.
*A predicate is something that satisfies a specific requirement.
*Use predicates and function objects to give standard algorithms a wide range of meaning.
*Concurrency is the act of executing serval tasks simultaneously.
*A computation that can potentially executed with other computations is a task. A thread is the system-level
representation of a task. A task to be executed concurrently with other tasks is launched by constructing
a thread with the task as its argument.
*Threads of a program share a single address space. In this, threads differ from processes, which generally do not
share data.
