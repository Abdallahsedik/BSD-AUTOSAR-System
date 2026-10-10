classdef RadarStatus_T <Simulink.IntEnumType
     enumeration
         RADAR_OK (0) %Radar data is valid and can be used by the algorithm 
         RADAR_FAIL(1)%Radar data is invalid, missing, or out of range and shall not be used
     end
      methods (Static = true)
        function retVal = getDefaultVal(), retVal = RadarStatus_T.RADAR_OK; end
        function headerFile = getHeaderFile(), headerFile = 'Rte_Type.h'; end
    end
end