README
------
Name:		Nicholas Rebhun
NetID:		zx3555
Course:		CS-3590-02, Data Communications and Networking
Instructor:	Doctor Levent Ertaul

------
Simulation of Selective-Reject (Selective-Repeat) ARQ.

The server is represented by the lefthand column, and the client is represented by the righthand column.
Traveling circles represent messages sent between the two endpoints. 
Each element is color-coded, according to the provided key.

In Selective Reject ARQ, packets are sent from the server, and upon reaching the destination, the client checks for proper packet sequence. 

If the received packet is the next in the sequence, the client sends an acknowledge to the server.

If the packet received is not the next in the sequence, the client sends a reject, and buffers data received until the proper packet is received.

If the server receives an acknowledge, that packet sequence number is marked as received properly as well as any unmarked packet sequence numbers prior to that one.

If the server receives a reject, the server resends the "oldest" packet not yet acknowledged.

------
Usage:
- Two user-modifiable settings:
  * Window Size
  * Packets per second
- To begin the simulation, simply press the accordingly labeled button.

------
Known Issues:
* When end of simulation is reached, the final node(s) may not change color properly.
* When the simulation has been started, the simulation cannot be restarted unless the file is re-opened, otherwise the traveling spheres are all shifted.
* Server/Client text may not be aligned properly on some screen resolutions