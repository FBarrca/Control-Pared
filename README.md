# Control de Seguimiento de Pared

Control de seguimiento de pared para el robot Turtlebot3 mediante  usando ROS2. El control corre en MATLAB y retransmite los datos a ROS2.

Este modelo está pensado para ser usado en MATLAB 2022a utilizando la librería ROS Toolbox.

Para empezar, se necesita instalar MATLAB y descargar el código de GitHub.


## Installation

Este modelo está pensado para ser usado en MATLAB 2022a utilizando la librería ROS Toolbox.
Para empezar, se necesita instalar MATLAB y descargar el código de GitHub.

### Git

```bash
git clone https://github.com/FranciscoBarCa/Control-Velocidad.git
cd Control-Velocidad
matlab -r EnsayoControlVelocidad #Asegurarse es 2022a
```

En caso de no tener Git instalado puede descargar manualmente el repositiorio y descomprimirlo.


## Usage

Se recomienda usar el archivo Angulo2.slx, este tiene los parametros como bloques de simulink y es más fácil de modificar. Además tiene preconfigurado un offset para evitar que el robot tienda a irse a la derecha.

