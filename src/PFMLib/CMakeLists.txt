project(PFMLib)

set(PFMLib_Src
    Budgeting.cpp
    Budgeting.h
    FinanceManager.cpp
    FinanceManager.h
    main.h
    Transaction.cpp
    Transaction.h
    User.cpp
    User.h
)

add_library(PFMLib ${PFMLib_Src})