include "llvm/Target/Target.td"
include "EVMInstrFormats.td"
include "EVMInstrInfo.td"
include "EVMSchedule.td"

def FeatureCmp         : SubtargetFeature<"cmp", "HasCmp", "true",
                                "Enable 'cmp' instructions.">;
class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, Cpu0GenericItineraries, Features>;
def : Proc<"EVM", [FeatureCmp]>;
def EVMReg: Register<"EVM">, DwarfRegNum<[0,0,0]>;
def EVMInstrInfo : InstrInfo;
def EVMCommon : RegisterClass<"EVM", [i256], 256, (add EVMReg)>;
def EVMTable : Target {
  let InstructionSet = EVMInstrInfo;
}
