classdef TurnSignal_T < Simulink.IntEnumType
    enumeration
        TURN_OFF (0) % No turn signal active
        TURN_LEFT (1) % Left turn signal active
        TURN_RIGHT (2) % Right turn signal active
    end
    methods (Static = true)
        function retVal = getDefaultVal()
            retVal = TurnSignal_T.TURN_OFF; 
        end
        function headerFile = getHeaderFile()
            headerFile = 'Rte_Type.h'; 
        end
        function dataScope = getDataScope()
            dataScope = 'Imported'; 
        end
        function storageType = getStorageType()
            storageType = 'uint8'; 
        end
    end
end