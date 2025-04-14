function PI_params = calculate_PI_params(pmsm, inverter)

%Parameters
zeta1=0.707;
zeta2=1;
Rt_speed=0.06;
gamma=0.6;
%pmsm.Rs=pmsm.Rs+inverter.R_board;

%Speed PI

wn_speed=5*zeta1/Rt_speed;
alpha=0.002;
a=pmsm.B/pmsm.J;
b=1.5*alpha*((pmsm.p)^2 * pmsm.FluxPM)/pmsm.J;
PI_params.Kp_speed=(2*zeta1*wn_speed-a)/b;
PI_params.Ti_speed=(2*zeta1*wn_speed-a)/(wn_speed^2);
PI_params.Ki_speed=PI_params.Kp_speed / PI_params.Ti_speed;

%Current PI 

%Il modello Simulink utilizza un'unica configurazione per la corrente q e d
%poiché nel caso specifico, i parametri sono uguali e le configurazioni
%risultano equivalenti
L=pmsm.Lq;

wn_i = (1/(1-gamma))*(pmsm.Rs/L);
PI_params.Kp_i=(2*zeta2*wn_i*L)-pmsm.Rs;
PI_params.Ti_i=(2*zeta2*wn_i*L-pmsm.Rs)/(L*(wn_i)^2);
PI_params.Ki_i=PI_params.Kp_i/PI_params.Ti_i;

end