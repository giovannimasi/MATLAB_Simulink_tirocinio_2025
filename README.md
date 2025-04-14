### Tirocinio 2025 - Matlab Simulink

Il repository contiene i progetti MATLAB/Simulink utilizzati durante il corso del tirocinio. In particolare sono contenuti i progetti di esempio modificati ad hoc per portare a termine gli obiettivi richiesti, successivamente analizzati.
# Parte 1
L'obiettivo di questa fase è prendere confidenza con l'hardware, con il software Simulink, infine con la tecnica di controllo basata sul controllo PI in cascata, outer-loop in velocità e inner-loop in corrente, basato sulla schematizzazione del sistema a 3 fasi in una configurazione semplificata a due correnti (diretta e di quadratura), ottenuta tramite trasformazioni di Clarke e Park.

In questa parte viene utilizzata la configurazione hardware così composta: scheda di controllo LAUNCHPAD-F28069M, inverter BOOSTXL-DRV8305EVM, motore trifase brushless Anaheim-BLY172S-24V-4000.

Le fasi di lavoro sono elencate di seguito:

- OpenloopADCOffsetExample: viene utilizzato l'esempio predefinito per verificare il corretto funzionamento della configurazione hardware e il corretto calcolo dell'ADC Offset;
- EstimatePMSMParamBlocks: non realmente necessario poiché a conoscenza dei parametri specifici del motore;
- FOC-Hall Example e HallOffsetExample: nel tentativo di utilizzare il sensore a effetto Hall, è risultata inefficace la configurazione hardware, in quanto non sono presenti progetti che si occupano della calibrazione del sensore per la configurazione utilizzata;
- SensorlessFocFOSMOExample: il progetto principalmente utilizzato nel corso della prima parte, in cui sono stati ricostruiti i controller PI e sono stati calcolati i parametri dei controllori, basandosi sul modello matematico del processo.

# Parte 2
Una volta esser riusciti a mettere mano sul controllo vero e proprio, è stato richiesto di metterlo in pratica su una diversa configurazione, testando la robustezza del controllo su una coppia di motori, in cui il motore 2 genera una coppia resistente che ostacolerà la rotazione del motore 1. Il motore 1 deve essere comunque in grado, con il controllo implementato anche precedentemente, di mantenere la velocità richiesta anche a fronte di variazioni della coppia resistente.

La configurazione hardware è così composta: scheda di controllo LAUNCHPAD-F29379D, inverter BOOSTXL-DRV8305EVM, motore trifase brushless Teknic-2310P.

Sono stati provati due approcci, entrambi risultati funzionali:

- QuadratureEncoderOffsetExample e DualMotorDynoExample: in cui il controllo rimane lo stesso studiato nella fase 1, ma necessitava dell'utilizzo di un encoder a quadratura, di cui è stata fatta la calibrazione dell'offset per entrambi i motori correttamente;
- DualMotorDynoUsingC2000ProcessorsExample: la cui unica differenza degna di nota è l'utilizzo di un osservatore per la stima asintotica della velocità, piuttosto che il sensore

# Conslusioni

Tutti i test sono stati svolti prima in simulazione, poi su hardware, in modo da garantire sicurezza contro guasti e inefficienza.
