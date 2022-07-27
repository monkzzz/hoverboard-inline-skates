# RC Hoverboard Inline Skates

Remote control inline skates made with hoverboard wheels.

The hoverboard wheels electronics are based on GD32 microprocessors and are salvaged from the original hoverboard.

Each wheel has it's own pcb and microprocessor, running on a master/slave system.

It currently receives input from UART comming from a TTGO esp32.

The input is received by UART, comming from an TTGO esp32, which controls their speed, steer and lights.

There is also information the GD32 sends to the remote like battery voltage.

This project is in a very early stage and is being developed slowly as the remote controller code is also being developed.

Extra safety measures like a deadman's trigger, a simulated electronic gear shift and a obstacle detector is or will be implemented, but for now is not 100% safe or viable.
