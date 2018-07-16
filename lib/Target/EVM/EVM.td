include "llvm/Target/Target.td"
include "EVMInstrInfo.td"
def i256: ValueType<256,8>;
def EVMReg: Register<"EVM">, DwarfRegNum<[0,0,0]>;
def EVMInstrInfo : InstrInfo;
def EVMCommon : RegisterClass<"EVM", [i256], 256, (add EVMReg)>;
def EVMTable : Target {
  let InstructionSet = EVMInstrInfo;
}
