set(LLVM_TARGET_DEFINITIONS EVM.td)
tablegen(LLVM EVMGenInstrInfo.inc -gen-instr-info)
add_public_tablegen_target(EVMCommonTableGen)
add_llvm_target(EVMCodeGen
	EVMTargetMachine.cpp
        EVMInstrInfo.cpp
)
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
