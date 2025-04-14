function mcb_param_est_StopFunc(~)
% mcb_param_est_StopFunc Reads the estimated parameters from the base workspace and stores them in structure 'motorParam'

% Copyright 2020 The MathWorks, Inc.

motorParam = evalin('base','motorParam'); 
if isempty(evalin('base','Rs')) 
    motorParam.Rs = 0; 
else
    motorParam.Rs = double(evalin('base','Rs'));
end
if isempty(evalin('base','Ld')) 
    motorParam.Ld = 0; 
else
    motorParam.Ld = double(evalin('base','Ld'));
end
if isempty(evalin('base','Lq')) 
    motorParam.Lq = 0; 
else
    motorParam.Lq = double(evalin('base','Lq'));
end
if isempty(evalin('base','Ke')) 
    motorParam.Ke = 0; 
else
    motorParam.Ke = double(evalin('base','Ke'));
end
if isempty(evalin('base','J')) 
    motorParam.J = 0; 
else
    motorParam.J = double(evalin('base','J'));
end
if isempty(evalin('base','B')) 
    motorParam.B = 0; 
else
    motorParam.B = double(evalin('base','B'));
end
motorParam.FluxPM     = double((motorParam.Ke)/(sqrt(3)*2*pi*1000*motorParam.p/60));  %PM flux computed from Ke
motorParam.T_rated    = double((3/2)*motorParam.p*motorParam.FluxPM*motorParam.nomCurrent);    %Get T_rated from I_max
inverter = evalin('base','inverter');
if isempty(evalin('base','Ia_avg_cal')) 
    motorParam.Ia_avg_cal = 0; 
else
    motorParam.Ia_avg_cal = double(evalin('base','Ia_avg_cal'));
end
if isempty(evalin('base','Ib_avg_cal')) 
    motorParam.Ib_avg_cal = 0; 
else
    motorParam.Ib_avg_cal = double(evalin('base','Ib_avg_cal'));
end
assignin('base', 'motorParam', motorParam);
assignin('base', 'inverter', inverter);
evalin( 'base', 'clear Rs Ld Lq Ke J B Ia_avg_cal Ib_avg_cal');
