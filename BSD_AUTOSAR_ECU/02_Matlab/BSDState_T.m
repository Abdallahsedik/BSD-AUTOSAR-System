classdef BSDState_T < Simulink.IntEnumType
    enumeration
        BSD_CLEAR   (0) 
        BSD_WARNING (1) 
        BSD_ALERT   (1) 
    end
    methods (Static = true)
        function retVal = getDefaultVal()
            retVal = BSDState_T.BSD_CLEAR; 
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