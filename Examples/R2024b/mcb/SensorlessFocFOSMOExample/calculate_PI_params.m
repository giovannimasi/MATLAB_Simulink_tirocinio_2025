function PI_params = calculate_PI_params(pmsm, inverter)
%Parameters
zeta1=0.707;
zeta2=1;
Rt_speed=0.06;
gamma=0.8;

%Speed PI

wn_speed=5*zeta1/Rt_speed;
alpha=0.0009;
a=pmsm.B/pmsm.J;
b=1.5*alpha*((pmsm.p)^2 * pmsm.FluxPM)/pmsm.J;
PI_params.Kp_speed=(2*zeta1*wn_speed-a)/b;
PI_params.Ti_speed=(2*zeta1*wn_speed-a)/(wn_speed^2);
PI_params.Ki_speed=PI_params.Kp_speed / PI_params.Ti_speed;

%Valori predefiniti
%PI_params.Kp_speed=0.3830;
%PI_params.Ti_speed=0.0757;
%PI_params.Ki_speed=5.0560;

%Current PI 

%Il modello Simulink utilizza un'unica configurazione per la corrente q e d
%poiché nel caso specifico, i parametri sono uguali e le configurazioni
%risultano equivalenti

L=pmsm.Lq;

wn_i = (1/(1-gamma))*(pmsm.Rs/L);
PI_params.Kp_i=(2*zeta2*wn_i*L)-pmsm.Rs;
PI_params.Ti_i=(2*zeta2*wn_i*L-pmsm.Rs)/(L*(wn_i)^2);
PI_params.Ki_i=PI_params.Kp_i/PI_params.Ti_i;

%Valori predefiniti
%PI_params.Kp_i=1.2758;
%PI_params.Ti_i=0.0015;
%PI_params.Ki_i=859.7751;

end