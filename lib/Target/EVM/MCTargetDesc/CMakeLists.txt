
add_llvm_library(LLVMEVMDesc
	EVMMCTargetDesc.cpp
	)
add_dependencies(LLVMEVMDesc EVMCommonTableGen)
