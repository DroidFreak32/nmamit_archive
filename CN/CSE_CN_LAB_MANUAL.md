Department of Computer Science and EngineeringNetwork Lab CS602DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERINGComputer NetworksLab Manual

6th Semester, B.E.

Submitted By:

Ravi B, Lecturer, Dept. of CSE.

Department of Computer Science and EngineeringNetwork Lab CS602LESSON PLAN

Prerequisite:

 Sound knowledge in C/C++,  Linux

 Basic knowledge in Computer Networks

Objectives:

To   provide   a   good   understanding   of  the   salient   features   of   network   Programming.   Students   areexpected to understand the network concept in detail and to program using C/C++ programminglanguage.

Learning outcome and end use:

By the end of the course, the students should be able to :-

 Have a detailed understanding of the underlying design principles of computers comunication. Be   able   to   apply   basic   concept   of  TCP/IP  protocol   and   the   methods   of       programmingtechniqes.

 Recognize  the   features  of  client/server  systems  and   programs  with  a  view   to  be  able  toimplement simple system in this model

 Analyse ,develop and implement error-detection and correction, and encryption algorithms Be able to simulate network protocols to check the functionality of the protocols.Rules of behavior in the laboratory:

Every laboratory sessions begins SHARP at the specified time in the schedule.

Each lab session is two hours long. Students are advised to bring their record and observationbooks.

Strict discipline should be maintained throughout the lab.

Punctuality should be followed by each and every student.

Food, drinks and cell phone are not allowed inside the laboratory











Method of Assessment:

Writing Algorithms

Program Execution

Viva Voce

-

-

-

List of Experiments

Department of Computer Science and EngineeringNetwork Lab CS602Note: Student is required to solve one problem from PART-A and one problem from PART-B.PART A – Simulation Experiments

The following experiments shall be conducted using either NS2/OPNET or any other simulators.1. Simulate a three nodes point-to-point network with duplex links between them. Set the queuesize vary the bandwidth and find the number of packets dropped.

2. Simulate a four node point-to-point network, and connect the links as follows: n0-n2, n1-n2and n2-n3. Apply TCP agent between n0-n3 and UDP n1-n3. Apply relevant applications overTCP  and   UDP  agents   changing   the   parameter   and   determine   the   number   of   packets   byTCP/UDP.

Simulate the different types of Internet traffic such as FTP a TELNET over a network andanalyze the throughput.

3.

4. Simulate the transmission of ping messaged over a network topology consisting of 6 nodes and5.

find the number of packets dropped due to congestion.

Simulate an Ethernet LAN using N-nodes (6-10), change error rate and data rate and comparethe throughput.

6. Simulate an Ethernet LAN using N nodes and set multiple traffic nodes and determine collisionacross different nodes.

7. Simulate an Ethernet LAN using N nodes and set multiple traffic nodes and plot congestionwindow for different source/destination.

8. Simulate   simple   ESS   and   with   transmitting   nodes   in   wire-less   LAN   by   simulation   anddetermine the performance with respect to transmission of packets.

### The following experiments shall be conducted using C/C++.

PART B

1. Write a program for error detecting code using CRC-CCITT (16-bits).

2. Write a program for frame sorting technique used in buffers.

3. Write a program for distance vector algorithm to find suitable path for transmission.4. Using TCP/IP sockets, write a client-server program to make client sending the file name andthe server to send back the contents of the requested file if present.

5. Using UDP SOCKETS, write a client-server program to make the client sending two numbersand an operator, and server responding with the result. Display the result and appropriatemessages for invalid inputs at the client side.

.Write a program for Hamming Code generation for error detection and correction.6.

7. Write a program for simple RSA algorithm to encrypt and decrypt the data

8. Write a program for congestion control using Leaky bucket algorithm.

Part A Experiments

Department of Computer Science and EngineeringNetwork Lab CS6021. Overview of NS-2

1.1 Introduction to NS-2

NS-2 is an event driven packet level network simulator developed as part of the VINT project (VirtualInternet Testbed). This was a collaboration of many institutes including UC Berkeley, AT&T, XEROXPARC and ETH. Version 1 of NS was developed in 1995 and with version 2 released in 1996. Version2 included a scripting language called Object oriented Tcl (OTcl). It is an open source softwarepackage   available   for   both  Windows   and   Linux       platforms.   It   provides   substantial   support   forsimulation of TCP, routing, and multicast protocols over wired and wireless (local and satellite)networks.

NS-2 has many and expanding uses including:

 To evaluate the performance of existing network protocols.

 To evaluate new network protocols before use.

 To run large scale experiments not possible in real experiments.

 To simulate a variety of ip networks

1.2 Downloading/Installing ns

You can download the package from http://www.isi.edu/nsnam/ns/ns-build.html. There are two waysto build ns: from the various packages or ‘all-in-one’ package. For simplicity, it is recommended tostart with the ‘all-in-one’ package. Please refer http://www.isi.edu/nsnam/ns/ns-problems.html for anyinstallation problems.

1.3 Starting ns

You start ns with the command 'ns <tclscript>' (assuming that you are in the directory with the nsexecutable, or that your path points to that directory), where '<tclscript>' is the name of a Tcl (ToolCommand Language) script file which defines the simulation scenario (i.e. the topology and theevents). You can also just start ns without any arguments and enter the Tcl commands in the Tcl shell,but that is definitely less comfortable.

1.4 Starting nam (Network Animator)

You can either start nam with the command 'nam <nam-file>' where '<nam-file>' is the name of a namtrace file that was generated by ns, or you can execute it directly out of the Tcl simulation script for thesimulation which you want to visualize.

1.5 Architecture of NS-2

Department of Computer Science and EngineeringNetwork Lab CS602As shown in the simplified user's view of Figure, NS is an Object-oriented Tcl (OTcl) script interpreterthat has a simulation event scheduler and network component object libraries, and network set-up(plumbing) module libraries.

An OTcl script will do the following.

Initiates an event scheduler.



 Sets up the network topology using the network objects.

 Tells traffic sources when to start/stop transmitting packets through the event schedulerAnother major component of NS besides network objects is the event scheduler. An event in NS is apacket ID that is unique for a packet with scheduled time and the pointer to an object that handles theevent. The event scheduler in NS-2 performs the following tasks:

 Organizes the simulation timer.

 Fires events in the event queue.



Invokes network components in the simulation.

Depending on the user’s purpose for an OTcl simulation script, simulation results are stored as tracefiles, which can be loaded for analysis by an external application:

1.

2.

A NAM trace file (file.nam) for use with the Network Animator Tool

A Trace file (file.tr) for use with XGraph or TraceGraph [11].

![Im16](images/Im16)

Department of Computer Science and EngineeringNetwork Lab CS602TclCL is the language used to provide a linkage between C++ and OTcl. Toolkit Command Language(Tcl/OTcl) scripts are written to set up/configure network topologies. TclCL provides linkage for classhierarchy, object instantiation, variable binding and command dispatching. OTcl is used for periodic ortriggered events.

1.6 NS-2 features

NS-2 implements the following features

1. Router queue Management Techniques DropTail, RED, CBQ,

2. Multicasting

3. Simulation of wireless networks

 Developed by Sun Microsystems + UC Berkeley (Daedalus Project) Terrestrial (cellular, adhoc, GPRS, WLAN, BLUETOOTH), satellite

 DSR, TORA, DSDV and AODV.

IEEE 802.11 can be simulated, Mobile-IP, and adhoc protocols such as4. Traffic Source Behavior- www, CBR, VBR

5. Transport Agents- UDP/TCP

6. Routing

7. Packet flow

8. Network Topology

9. Applications- Telnet, FTP, Ping

10.

Tracing Packets on all links/specific links

1.7 NAM (Network Animator)

NAM provides a visual interpretation of the network topology created.  Below youcan see a screenshot of a nam window where the most important functions are being explained.![Im20](images/Im20)

Department of Computer Science and EngineeringNetwork Lab CS602Its features are as follows:

 Provides a visual interpretation of the network created

 Can be executed directly from a Tcl script

 Controls include play, stop ff, rw, pause, a display speed controller and a Presents information such as throughput, number packets on each link. Provides a drag and drop interface for creating topologies.

packet monitor facility.

1.8 XGraph

XGraph is an X-Windows application that includes:

Interactive plotting and graphing



 Animation and derivatives

To use XGraph in NS-2 the executable can be called within a TCL Script. This will then load a graphdisplaying the information visually displaying the information of the trace file produced from thesimulation.

![Im25](images/Im25)

Department of Computer Science and EngineeringNetwork Lab CS602XGraph running comparing three trace files in a graph1.9  TraceGraph

TraceGraph is a trace file analyzer that runs under Windows, Linux and UNIX systems and requiresMat lab 6.0 or higher.

TraceGraph supports the following trace file formats.

 Wired

 Satellite

 Wireless

2. OTcl Scripting with NS-2

In NS-2, the network is constructed using nodes which are connected using links. Events are scheduledto pass between nodes through the links. Nodes and links can have various properties associated withthem. Agents can be associated with nodes and they are responsible for generating different packets(e.g. TCP agent  or UDP agent). The traffic  source is an application  which is associated  with aparticular agent (e.g. ping application).

This diagram shows two nodes, a link, an agent and an application.![Im32](images/Im32)

![Im33](images/Im33)

Department of Computer Science and EngineeringNetwork Lab CS6022.1 How to start?

First of all, you need to create a simulator object. This is done with the command

set ns [new Simulator]

Now we open a file for writing that is going to be used for the nam trace data.

set nf [open out.nam w]

$ns namtrace-all $nf

The first line opens the file 'out.nam' for writing and gives it the file handle 'nf'. In the second line wetell the simulator object that we created above to write all simulation data that is going to be relevantfor nam into this file. The next step is to add a 'finish' procedure that closes the trace file and startsnam.

proc finish {} {

global ns nf

$ns flush-trace

close $nf

exec nam out.nam &

exit 0

}

The last line finally starts the simulation

$ns run

2.2 Node creation and linking

The following two lines define the two nodes. (Note: You have to insert the code in this section beforethe line '$ns run', or even better, before the line '$ns at 5.0 "finish"').

set n0 [$ns node]

set n1 [$ns node]

A new node object is created with the command '$ns node'. The above code creates two nodes andassigns them to the handles 'n0' and 'n1'. The next line connects the two nodes.

$ns duplex-link $n0 $n1 1Mb 10ms DropTail

This line tells the simulator object to connect the nodes n0 and n1 with a duplex link with thebandwidth 1Megabit, a delay of 10ms and a DropTail queue.

Now   you   can   save   your   file   and   start   the   script   with   'ns   example1.tcl'.   nam   will   be   startedautomatically and you should see an output that resembles the picture below.

Department of Computer Science and EngineeringNetwork Lab CS6022.3 Sending data

The next step is to send some data from node n0 to node n1. In ns, data is always being sent from one'agent' to another. So the next step is to create an agent object that sends data from node n0, andanother agent object that receives the data on node n1.

#create a UDP agent and attach it to node n0

set udp0 [new Agent/UDP]

$ns attach-agent $n0 $udp0

# create a CBR traffic source and attach it to udp0

set cbr0 [new Application/Traffic/CBR]

$cbr0 set packetSize_ 500

$cbr0 set interval_ 0.005

$cbr0 attach-agent $udp0

These lines create a UDP agent and attach it to the node n0, then attach a CBR traffic generator to theUDP agent. CBR stands for 'constant bit rate'. Line 7 and 8 should be self-explaining. The packet Sizeis being set to 500 bytes and a packet will be sent every 0.005 seconds (i.e. 200 packets per second).The next lines create a Null agent which acts as traffic sink and attach it to node n1.

set null0 [new Agent/Null]

$ns attach-agent $n1 $null0

Now the two agents have to be connected with each other.

$ns connect $udp0 $null0

And now we have to tell the CBR agent when to send data and when to stop sending. It's probably bestto put the following lines just before the line '$ns at 5.0 "finish"'.

$ns at 0.5 "$cbr0 start"

$ns at 4.5 "$cbr0 stop"

Now you can save the file and start the simulation again. When you click on the 'play' button in thenam window, you will see that after 0.5 simulation seconds, node 0 starts sending data packets to node1. You might want to slow nam down then with the 'Step' slider.

![Im41](images/Im41)

Department of Computer Science and EngineeringNetwork Lab CS602Add the following two lines to your CBR agent definitions.

$udp0 set class_ 1

$udp1 set class_ 2

The parameter 'fid_' stands for 'flow id'.

Now you can add the following piece of code to your Tcl script, preferably at the beginning after thesimulator object has been created, since this is a part of the simulator setup.

$ns color 1 Blue

$ns color 2 Red

This code allows you to set different colors for each flow id.

You can add the following line to your code to monitor the queue for the link from n2 to n3.$ns duplex-link-op $n2 $n3 queuePos 0.5

You can see the packets in the queue now, and after a while you can even see how the packets arebeing dropped, though (at least on my system, I guess it might be different in later or earlier releases)only blue packets are being dropped. But you can't really expect too much 'fairness' from a simpleDrop Tail queue. So let's try to improve the queuing by using a SFQ (stochastic fair queuing) queue forthe link from n2 to n3. Change the link definition for the link between n2 and n3 to the following line.$ns duplex-link $n3 $n2 1Mb 10ms SFQ

The queuing should be 'fair' now. The same amount of blue and red packets should be dropped.Experiment No. 1

![Im46](images/Im46)

Department of Computer Science and EngineeringNetwork Lab CS602Problem Statement:

Simulate a three nodes point-to-point network with duplex links between them. Set the queue size varythe bandwidth and find the number of packets dropped.

#File Name: ns_exp1.tcl

#Description: Simulating simple three nodes point-to-point network

##################################################################

set ns [new Simulator]

#Open a new file for NAMTRACE

set nf [open out.nam w]

$ns namtrace-all $nf

#Open a new file to log TRACE

set tf [open out.tr w]

$ns trace-all $tf

#Body of the finish procedure

proc finish {} {

global ns nf tf

$ns flush-trace

close $nf

close $tf

exec nam out.nam &

exit 0

}

#Create Nodes

set n0 [$ns node]

set n1 [$ns node]

set n2 [$ns node]

#Create Links between Nodes

$ns duplex-link $n0 $n1 1Mb 10ms DropTail

$ns duplex-link $n1 $n2 1Mb 10ms DropTail

#Set the queue limit - default is 50 packets

$ns queue-limit $n0 $n1 50

$ns queue-limit $n1 $n2 50

#Create Transport Agent

set udp0 [new Agent/UDP]

$ns attach-agent $n0 $udp0

set null0 [new Agent/Null]

$ns attach-agent $n2 $null0

$ns connect $udp0 $null0

#Create Application to generate traffic

set cbr0 [new Application/Traffic/CBR]

$cbr0 set packetSize_ 500

$cbr0 set interval_ 0.005

$cbr0 attach-agent $udp0

#Start and Stop generating traffic

Nam output:

Department of Computer Science and EngineeringNetwork Lab CS602Experiment No. 2

Problem Statement:

Simulate a four node point-to-point network, and connect the links as follows: n0-n2, n1-n2 and n2-n3.Apply TCP agent between n0-n3 and UDP n1-n3. Apply relevant applications over TCP and UDPagents changing the parameter and determine the number of packets by TCP/UDP.

#File Name: ns_exp2.tcl

#Description:  Simulating four node point-to-point network with TCP and UDP agent#################################################################################set ns [new Simulator]

#Open a new file for NAMTRACE

set nf [open out.nam w]

$ns namtrace-all $nf

#Open a new file to log TRACE

set tf [open out.tr w]

$ns trace-all $tf

#Body of the 'finish' procedure

proc finish {} {

global ns nf tf

$ns flush-trace

close $nf

close $tf

exec nam out.nam &

exit 0

}

#Create Nodes

set n0 [$ns node]

set n1 [$ns node]

set n2 [$ns node]

set n3 [$ns node]

![Im54](images/Im54)

Department of Computer Science and EngineeringNetwork Lab CS602#Create Links between Nodes

$ns duplex-link $n0 $n2 1Mb 10ms DropTail

$ns duplex-link $n1 $n2 1Mb 10ms DropTail

$ns duplex-link $n2 $n3 1Mb 10ms DropTail

#Set the queue limit - default is 50 packets

$ns queue-limit $n0 $n2 50

$ns queue-limit $n1 $n2 50

$ns queue-limit $n2 $n3 50

#Create TCP Agent between node 0 and node 3

set tcp0 [new Agent/TCP]

$ns attach-agent $n0 $tcp0

set sink0 [new Agent/TCPSink]

$ns attach-agent $n3 $sink0

$ns connect $tcp0 $sink0

#Create FTP Application for TCP Agent

set ftp0 [new Application/FTP]

$ftp0 attach-agent $tcp0

#Specify TCP packet size

Agent/TCP set packetSize_ 1000

#Create UDP Agent between node 1 and node 3

set udp0 [new Agent/UDP]

$ns attach-agent $n1 $udp0

set null0 [new Agent/Null]

$ns attach-agent $n3 $null0

$ns connect $udp0 $null0

#Create CBR Application for UDP Agent

set cbr0 [new Application/Traffic/CBR]

$cbr0 set packetSize_ 500

$cbr0 set interval_ 0.005

$cbr0 attach-agent $udp0

#Start and Stop FTP Traffic

$ns at 0.75 "$ftp0 start"

$ns at 4.75 "$ftp0 stop"

#Start and Stop CBR traffic

$ns at 0.5 "$cbr0 start"

$ns at 4.5 "$cbr0 stop"

#Stop the simulation

$ns at 5.0 "finish"

#Run the simulation

$ns run

NAM output:

Department of Computer Science and EngineeringNetwork Lab CS602Experiment No. 3

Problem Statement:

Simulate the different types of Internet traffic such as FTP a TELNET over a network and analyze thethroughput.

#File Name: ns_exp3.tcl

#Description: Simulating different types of Internet traffic

############################################################

set ns [new Simulator]

#Open a new file for NAMTRACE

set nf [open out.nam w]

$ns namtrace-all $nf

#Open a new file to log TRACE

set tf [open out.tr w]

$ns trace-all $tf

#Body of the 'finish' procedure

proc finish {} {

global ns nf tf

$ns flush-trace

close $nf

close $tf

exec nam out.nam &

exit 0

}

#Create Nodes

set n0 [$ns node]

set n1 [$ns node]

set n2 [$ns node]

set n3 [$ns node]

![Im62](images/Im62)

Department of Computer Science and EngineeringNetwork Lab CS602#Create Links between Nodes

$ns duplex-link $n0 $n2 1Mb 10ms DropTail

$ns duplex-link $n1 $n2 1Mb 10ms DropTail

$ns duplex-link $n2 $n3 1Mb 10ms DropTail

#Set the queue limit - default is 50 packets

$ns queue-limit $n0 $n2 50

$ns queue-limit $n1 $n2 50

$ns queue-limit $n2 $n3 50

#Create TCP Agent between node 0 and node 3

set tcp0 [new Agent/TCP]

$ns attach-agent $n0 $tcp0

set sink0 [new Agent/TCPSink]

$ns attach-agent $n3 $sink0

$ns connect $tcp0 $sink0

#Create FTP Application for TCP Agent

set ftp0 [new Application/FTP]

$ftp0 attach-agent $tcp0

#Specify TCP packet size

Agent/TCP set packetSize_ 1000

#Create TCP Agent between node 1 and node 3

set tcp1 [new Agent/TCP]

$ns attach-agent $n1 $tcp1

set sink1 [new Agent/TCPSink]

$ns attach-agent $n3 $sink1

$ns connect $tcp1 $sink1

#Create Telnet Application for TCP Agent

set telnet0 [new Application/Telnet]

$telnet0 set interval_ 0.005

$telnet0 attach-agent $tcp1

#Start and Stop FTP Traffic

$ns at 0.75 "$ftp0 start"

$ns at 4.75 "$ftp0 stop"

#Start and Stop Telnet traffic

$ns at 0.5 "$telnet0 start"

$ns at 4.5 "$telnet0 stop"

#Stop the simulation

$ns at 5.0 "finish"

#Run the simulation

$ns run

NAM output

Department of Computer Science and EngineeringNetwork Lab CS602Experiment No. 4

Problem Statement:

Simulate the transmission of ping messaged over a network topology consisting of 3-6 nodes and findthe number of packets dropped due to congestion.

#File Name: ns_exp4.tcl

#Description: transmission of ping messaged over a network topology

###################################################################

#Create a simulator object

set ns [new Simulator]

#Open a trace file

set nf [open out.nam w]

$ns namtrace-all $nf

#Define a 'finish' procedure

proc finish {} {

global ns nf

$ns flush-trace

close $nf

exec nam out.nam &

exit 0

}

#Create three nodes

set n0 [$ns node]

set n1 [$ns node]

set n2 [$ns node]

#Connect the nodes with two links

$ns duplex-link $n0 $n1 1Mb 10ms DropTail

$ns duplex-link $n1 $n2 1Mb 10ms DropTail

#Define a 'recv' function for the class 'Agent/Ping'

Agent/Ping instproc recv {from rtt} {

$self instvar node_

puts "node [$node_ id] received ping answer from \

$from with round-trip-time $rtt ms."

![Im70](images/Im70)

Department of Computer Science and EngineeringNetwork Lab CS602}

#Create two ping agents and attach them to the nodes n0 and n2

set p0 [new Agent/Ping]

$ns attach-agent $n0 $p0

set p1 [new Agent/Ping]

$ns attach-agent $n2 $p1

#Connect the two agents

$ns connect $p0 $p1

#Schedule events

$ns at 0.2 "$p0 send"

$ns at 0.4 "$p1 send"

$ns at 0.6 "$p0 send"

$ns at 0.6 "$p1 send"

$ns at 1.0 "finish"

#Run the simulation

$ns run

NAM output:

Node 2 sends                 Node 0 replies

Problem Statement:

Experiment No. 5

![Im75](images/Im75)

![Im76](images/Im76)

Department of Computer Science and EngineeringNetwork Lab CS602Simulate an Ethernet LAN using N-nodes (6-10), change error rate and data rate and compare thethroughput.

#File Name: ns_exp5.tcl

#Description: Simulate an Ethernet LAN using N-nodes (6 10)

######################################################################set ns [new Simulator]

#Open a new file for NAMTRACE

set nf [open out.nam w]

$ns namtrace-all $nf

#Open a new file to log TRACE

set tf [open out.tr w]

$ns trace-all $tf

#Body of the finish procedure

proc finish {} {

global ns nf tf

$ns flush-trace

close $nf

close $tf

exec nam out.nam &

exit 0

}

#Create Nodes

set n0 [$ns node]

set n1 [$ns node]

set n2 [$ns node]

set n3 [$ns node]

set n4 [$ns node]

set n5 [$ns node]

set n6 [$ns node]

set n7 [$ns node]

set n8 [$ns node]

set n9 [$ns node]

set n10 [$ns node]

#Create a Local Area Network (LAN) of 10 Nodes

$ns make-lan "$n0 $n1 $n2 $n3 $n4 $n5 $n6 $n7 $n8 $n9 $n10" 100Mb LLQueue/DropTail Mac/802_3

#Create TCP Agent between node 0 and node 3

set tcp0 [new Agent/TCP]

$ns attach-agent $n0 $tcp0

set sink0 [new Agent/TCPSink]

$ns attach-agent $n3 $sink0

$ns connect $tcp0 $sink0

Department of Computer Science and EngineeringNetwork Lab CS602#Create FTP Application for TCP Agent

set ftp0 [new Application/FTP]

$ftp0 attach-agent $tcp0

#Specify TCP packet size

Agent/TCP set packetSize_ 1000

#Start and Stop FTP Traffic

$ns at 0.75 "$ftp0 start"

$ns at 4.75 "$ftp0 stop"

#Stop the simulation

$ns at 5.0 "finish"

#Run the simulation

$ns run

NAM output:

Problem Statement:

Experiment No. 6

![Im85](images/Im85)

Department of Computer Science and EngineeringNetwork Lab CS602Simulate an Ethernet LAN using N nodes and set multiple traffic nodes and determine collision acrossdifferent nodes.

#File Name: ns_exp6.tcl

#Description:  Simulate an Ethernet LAN and set multiple traffic nodes######################################################################set ns [new Simulator]

#Open a new file for NAMTRACE

set nf [open out.nam w]

$ns namtrace-all $nf

#Open a new file to log TRACE

set tf [open out.tr w]

$ns trace-all $tf

#Body of the 'finish' procedure

proc finish {} {

global ns nf tf

$ns flush-trace

close $nf

close $tf

exec nam out.nam &

exit 0

}

#Create Nodes

set n0 [$ns node]

set n1 [$ns node]

set n2 [$ns node]

set n3 [$ns node]

set n4 [$ns node]

set n5 [$ns node]

set n6 [$ns node]

set n7 [$ns node]

set n8 [$ns node]

set n9 [$ns node]

#Create a Local Area Network (LAN) of 10 Nodes

$ns make-lan "$n0 $n1 $n2 $n3 $n4 $n5 $n6 $n7 $n8 $n9" 100Mb LLQueue/DropTail Mac/802_3

#Create TCP Agent between node 0 and node 3

set tcp0 [new Agent/TCP]

$ns attach-agent $n0 $tcp0

set sink0 [new Agent/TCPSink]

$ns attach-agent $n3 $sink0

$ns connect $tcp0 $sink0

#Create FTP Application for TCP Agent

Department of Computer Science and EngineeringNetwork Lab CS602set ftp0 [new Application/FTP]

$ftp0 attach-agent $tcp0

#Specify TCP packet size

Agent/TCP set packetSize_ 1000

#Create TCP Agent between node 1 and node 3

set tcp1 [new Agent/TCP]

$ns attach-agent $n1 $tcp1

set sink1 [new Agent/TCPSink]

$ns attach-agent $n3 $sink1

$ns connect $tcp1 $sink1

#Create Telnet Application for TCP Agent

set telnet0 [new Application/Telnet]

$telnet0 set interval_ 0.005

$telnet0 attach-agent $tcp1

#Start and Stop FTP Traffic

$ns at 0.75 "$ftp0 start"

$ns at 4.75 "$ftp0 stop"

#Start and Stop Telnet traffic

$ns at 0.5 "$telnet0 start"

$ns at 4.5 "$telnet0 stop"

#Stop the simulation

$ns at 5.0 "finish"

#Run the simulation

$ns run

Problem Statement:

Experiment No. 7

Department of Computer Science and EngineeringNetwork Lab CS602Simulate an Ethernet LAN using N nodes and set multiple traffic nodes and plot congestion windowfor different source/destination.

#File Name: ns_exp7.tcl

#Description:  Simulate an Ethernet LAN using N nodes and set multiple trafficnodes and plot congestion window for different source/destination.

###############################################################################set ns [new Simulator]

#Open a new file for NAMTRACE

set nf [open out.nam w]

$ns namtrace-all $nf

#Open a new file to log TRACE

set tf [open out.tr w]

$ns trace-all $tf

#Body of the 'finish' procedure

proc finish {} {

global ns nf tf

$ns flush-trace

close $nf

close $tf

exec nam out.nam &

exit 0

}

#Create Nodes

set n0 [$ns node]

set n1 [$ns node]

set n2 [$ns node]

set n3 [$ns node]

set n4 [$ns node]

set n5 [$ns node]

set n6 [$ns node]

set n7 [$ns node]

set n8 [$ns node]

set n9 [$ns node]

#Create a Local Area Network (LAN) of 10 Nodes

$ns make-lan "$n0 $n1 $n2 $n3 $n4 $n5 $n6 $n7 $n8 $n9" 100Mb LLQueue/DropTail Mac/802_3

#Create TCP Agent between node 0 and node 3

set tcp0 [new Agent/TCP]

$ns attach-agent $n0 $tcp0

set sink0 [new Agent/TCPSink]

$ns attach-agent $n3 $sink0

$ns connect $tcp0 $sink0

#Open a new file to log Congestion Window data

Department of Computer Science and EngineeringNetwork Lab CS602set cfile0 [open tcp0.tr w]

$tcp0 attach $cfile0

$tcp0 trace cwnd_

#Create FTP Application for TCP Agent

set ftp0 [new Application/FTP]

$ftp0 attach-agent $tcp0

#Specify TCP packet size

Agent/TCP set packetSize_ 1000

#Create TCP Agent between node 1 and node 3

set tcp1 [new Agent/TCP]

$ns attach-agent $n1 $tcp1

set sink1 [new Agent/TCPSink]

$ns attach-agent $n3 $sink1

$ns connect $tcp1 $sink1

#Open a new file to log Congestion Window data

set cfile1 [open tcp1.tr w]

$tcp1 attach $cfile1

$tcp1 trace cwnd_

#Create Telnet Application for TCP Agent

set telnet0 [new Application/Telnet]

$telnet0 set interval_ 0.005

$telnet0 attach-agent $tcp1

#Start and Stop FTP Traffic

$ns at 0.75 "$ftp0 start"

$ns at 4.75 "$ftp0 stop"

#Start and Stop Telnet traffic

$ns at 0.5 "$telnet0 start"

$ns at 4.5 "$telnet0 stop"

#Stop the simulation

$ns at 5.0 "finish"

#Run the simulation

$ns run

Problem Statement:

Experiment No. 8

Simulate simple ESS and with transmitting nodes in wire-less LAN by simulation and determine theperformance with respect to transmission of packets using NCTUNS

Department of Computer Science and EngineeringNetwork Lab CS602#File Name: ns_exp8.tcl

#Description: simple ESS and with transmitting nodes in wire-less LAN######################################################################1.

Click on “access point”. Goto wireless interface and tick on “show transmission range andthen click OK.

2. Double click on Router -> Node Editor and then

Left stack -> throughput of Incoming packets

Right stack -> throughput of Outgoing packets

3. Select mobile hosts and access points then click on.

Tools -> WLAN mobile nodes-> WLAN Generate infrastructure.Subnet ID: Port number of router (2)

Gateway ID: IP address of router

Part B Programs

4. Mobile Host 1

5. Mobile Host 1

6. Host(Receiver)

ttcp –t –u –s –p 3000 1.0.1.1

ttcp –t –u –s –p 3001 1.0.1.1

ttcp –r –u –s –p 3000

ttcp –r –u –s –p 3001

7. Run and then play to plot the graph.

![Im102](images/Im102)

Department of Computer Science and EngineeringNetwork Lab CS602Problem Statement:

Write a program for error detecting code using CRC-CCITT (16-bits).

Experiment No. 1

Theory:

It does error checking via polynomial division. In general, a bit string can be represented using apolynomial. Ex: 10010101110 can be represented as X10 + X7 + X5 + X3 + X2 + X.  All computations are donein modulo 2. The algorithm uses G(x) = X16+X12+X5 +1 as the generator polynomial whichused in HDLC, X.25, V.41, XMODEM, Bluetooth, SD and  many others.

Algorithm:

1. Given a bit string, append 0S to the end of it (the number of 0s is the same as the degree of the generatorpolynomial) . Let B(x) be the polynomial corresponding to B.

2. Divide B(x) by some agreed on polynomial G(x) (generator polynomial) and determine the remainderR(x). This division is to be done using Modulo 2 Division.

Define T(x) = B(x) –R(x),   (T(x)/G(x) => remainder 0)

3.

4. Transmit T, the bit string corresponding to T(x).

5.

Let T’ represent the bit stream the receiver gets and T’(x) the associated polynomial. The receiverdivides T’(x) by G(x). If there is a 0 remainder, the receiver concludes T = T’ and no error occurredotherwise, the receiver concludes an error occurred and requires a retransmission.

The algorithm can be implemented using a feedback shift-register as shown below.

![Im106](images/Im106)

Department of Computer Science and EngineeringNetwork Lab CS602/***************************************************************************  File Name   : crc.c

*

*  Description :Program for error detecting code using CRC-CCITT (16-bits).***************************************************************************/#include<stdio.h>

#define MAX_SIZE  20

//this strcuture 16 bit CRC

struct reg

{

int  bit;

}r[16];

int n;  // no. of input bits

int input[MAX_SIZE];

// function to implement the  encoder for CCITT-16 polynomial

void compute_crc()

{

int i,j;

int lmb; //corresponds to right most bit of the  shiftt-register circuit.for(j=0;j<(n+16);j++)

{

lmb=r[15].bit;

// shift the bits

for(i=15;i>0;i--)

{

r[i].bit=r[i-1].bit;

}

r[0].bit=input[j];

//if  leftmost bit is 1 , XOR the Dividend and Divisor.

//you can make your program portable by avoiding ^ operatorif(lmb==1)

{

r[12].bit = r[12].bit ^ lmb;

r[5].bit = r[5].bit ^ lmb;

r[0].bit = r[0].bit ^ lmb;

}

}

printf("Register content:\n");

for(i=15;i>=0;i--)

printf("%d ",r[i].bit);

for(i=n,j=15;j>=0;i++,j--)

input[i]=r[j].bit;

}

Department of Computer Science and EngineeringNetwork Lab CS602// function to check error in the transmitted data

int  check_err()

{

int i;

for(i=15;i>=0;i--)

{

if(r[i].bit != 0)

{

return i;

}

}

return 0;

}

void read_input()

{

int i;

printf("\nEnter the number of bits in the input:\n");

scanf("%d",&n);

printf("\nEnter the information bits(1's & 0's):\n");

for(i=0;i<n;i++)

scanf("%d", &input[i]);

for(i=n;i<(n+16);i++)

input[i]=0;

}

int  main()

{

int i;

read_input();

printf("\n\nAt sender:\n\n");

//initialize the registers

for(i=0;i<16;i++)

r[i].bit=0;

compute_crc();

printf("\nThe total message along with crc :\n");

for(i=0;i<(n+16);i++)

printf("%d ",input[i]);

printf("\n\nThe data is transmitted\n");

Department of Computer Science and EngineeringNetwork Lab CS602printf("\n\nAt receiver:\n\n");

printf("\nEnter the received data \n");

for(i=0;i<(n+16);i++)

scanf("%d", &input[i]);

//initialize the registers

for(i=0;i<16;i++)

r[i].bit=0;

// compute CRC

compute_crc();

// check for errors

if(i=check_err())

printf("\nThere is error in the received data. Error position=%d",i);else

printf("\nThe received data is fine");

return 0;

}

Experiment No. 2

Problem Statement:

Write a program for frame sorting technique used in buffers.

Theory:

The data link layer divides the stream of bits received from the network layer into manageable dataunits called frames. If frames are to be distributed to different systems on the network, the Data linklayer adds a header to the frame to define the sender and/or receiver of the frame. Each Data link layerhas its own frame format. One of the fields defined in the format is the maximum size of the data field.In other words, when datagram is encapsulated in a frame, the total size of the datagram must be lessthan this maximum size, which is defined by restriction imposed by the hardware and software used inthe network.

The value  of MTU differs  from one physical  network  to another  In order to make  IP protocolportable/independent of the physical network, the packagers decided to make the maximum length of![Im117](images/Im117)

Department of Computer Science and EngineeringNetwork Lab CS602the IP datagram equal to the largest Maximum Transfer Unit (MTU) defined so far. However for otherphysical networks we must divide the datagrams to make it possible to pass through these networks.This is called fragmentation. When a datagram is fragmented, each fragmented has its own header. Afragmented datagram may itself be fragmented if it encounters a network with an even smaller MTU.In another words, a datagram may be fragmented several times before it reached the final destinationand   also,   the   datagrams   referred   to   as   (frames   in   Data   link   layer)   may   arrives   out   of   order   atdestination. Hence sorting of frames need to be done at the destination to recover the original data.The following program simulates the frame sorting technique used in buffers.

Algorithm

1. Read a message from the keyboard

2. Divide the message into fixed size packets. Include sequence number and other information ineach packet.

3. Shuffle the packets (to  generate out of order packets )

4.

5. Display the ordered packets.

Order the packets based on sequence numbers

/***************************************************************************  File Name   : FrameSort.c

*

*  Description : A program for frame sorting technique used in buffers***************************************************************************/#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <time.h>

#define DATA_SZ 3

typedef struct packet

{

int SeqNum;

char Data[DATA_SZ+1];

}PACKET;

PACKET *readdata, *transdata;

time_t t ;

// Breaks the message into packets

int divide(char *msg)

{

int msglen, NoOfPacket, i, j;

msglen = strlen(msg);

NoOfPacket = msglen/DATA_SZ;

Department of Computer Science and EngineeringNetwork Lab CS602if((msglen%DATA_SZ)!=0)

NoOfPacket++;

readdata = (PACKET *)malloc(sizeof(PACKET) *NoOfPacket);

for(i = 0; i < NoOfPacket; i++)

{

readdata[i].SeqNum = i + 1;

for (j = 0; (j < DATA_SZ) && (*msg != '\0'); j++, msg++)

readdata[i].Data[j] = *msg;

readdata[i].Data[j] = '\0';

}

printf("\nThe Message has been divided as follows\n");

printf("\nPacket No.\tData\n\n");

for (i = 0; i < NoOfPacket; i++)

printf(" %d\t\t%s\n", readdata[i].SeqNum, readdata[i].Data);return NoOfPacket;

}

// shuffles the packets

void shuffle(int NoOfPacket)

{

int *Status;

int i, j, trans;

srand(time(&t)); //every time you shuffle,get different random sequenceStatus=(int * )calloc(NoOfPacket, sizeof(int));

transdata = (PACKET *)malloc(sizeof(PACKET) * NoOfPacket);

for (i = 0; i < NoOfPacket;)

{

trans = rand()%NoOfPacket;

if (Status[trans]!=1)

{

transdata[i].SeqNum = readdata[trans].SeqNum;

strcpy(transdata[i].Data, readdata[trans].Data);

i++;

Status[trans] = 1;

}

}

free(Status);

}

// sorts the packets

void sortframes(int NoOfPacket)

{

PACKET temp;

int i, j;

for (i = 0; i < NoOfPacket; i++)

{

for (j = 0; j < NoOfPacket - (i+1); j++)

{

Department of Computer Science and EngineeringNetwork Lab CS602if (transdata[j].SeqNum > transdata[j + 1].SeqNum)

{

temp.SeqNum = transdata[j].SeqNum;

strcpy(temp.Data, transdata[j].Data);

transdata[j].SeqNum = transdata[j + 1].SeqNum;strcpy(transdata[j].Data, transdata[j + 1].Data);transdata[j + 1].SeqNum = temp.SeqNum;

strcpy(transdata[j + 1].Data, temp.Data);

}

}

}

}

// receives packets out of order and calls sort function

void receive(int NoOfPacket)

{

int i;

printf("\nPackets received in the following order\n");

for (i = 0; i < NoOfPacket; i++)

printf("%4d",transdata[i].SeqNum);

sortframes(NoOfPacket);

printf("\n\nPackets in order after sorting..\n");

for (i = 0; i < NoOfPacket; i++)

printf("%4d",transdata[i].SeqNum);

printf("\n\nMessage received is :\n");

for (i = 0; i < NoOfPacket; i++)

printf("%s",transdata[i].Data);

}

int main()

{

char msg[25];

int NoOfPacket;

printf("\nEnter The message to be Transmitted :\n");

scanf("%[^\n]", msg);

NoOfPacket = divide(msg);

shuffle(NoOfPacket);

receive(NoOfPacket);

free(readdata);

free(transdata);

return 0;

}

Department of Computer Science and EngineeringNetwork Lab CS602Problem Statement:

Write a program for Distance Vector Algorithm to find suitable path for transmission.

Experiment No. 3

Theory:

The distance vector routing algorithm is sometimes called by other names, including the distributedBellman-Ford   routing   algorithm   and   the   Ford-Fulkerson   algorithm,   after   the   researchers   whodeveloped   it.   In   distance   vector   routing,   each   router   maintains   a   routing   table   indexed   by,   andcontaining one entry for, each router in subnet. This entry contains two parts: the preferred out goingline to use for that destination, and an estimate of the time or distance to that destination. The metricused might be number of hops, time delay in milliseconds, total number of packets queued along thepath, or something similar.

Algorithm:

1.

Read the initial routing table. The initial routing table for each router consists of the distancesto each of its neighbours.  Distance is assumed to be infinity if there is no direct path.2. To build the final routing table, each router communicates with each of its neighbours toupdate the routing table. The basic principle here is as follows:

Consider a node X that is interested in routing to

destination   Y   via   its   directly   attachedneighbour Z. Node X's distance table entry, Dx(Y,Z) is the sum of the cost of the direct  linkbetween X and Z,  c(X,Z),  plus neighbour  Z's currently known minimum cost path from itself(Z) to Y. That is:

Dx(Y, Z) = c(X, Z) + minw{Dz(Y, w)}

The minw term is taken over all of Z's directly attached neighbours (including X)Department of Computer Science and EngineeringNetwork Lab CS602/***************************************************************************  File Name   : DistVect.c

*

*  Description : A program for distance vector algorithm to find suitable***************************************************************************/path for transmission.

#include<stdio.h>

#define INFINITY 999

struct

{

int cost;

int via;

}routeTable[10][10];

int n; //no. of nodes

// function to  build  DV routing table

void build_route_table(int i)

{

int j,k,new_cost=0;

for(j=0;j<n;j++)

{

for(k=0;k<n && j!=i;k++)

{

// consider only adjacent routers

if(routeTable[i][j].cost != INFINITY)

{

new_cost =routeTable[i][j].cost+routeTable[j][k].cost;if(routeTable[i][k].cost > new_cost)

{

routeTable[i][k].cost=new_cost;

routeTable[i][k].via=routeTable[i][j].via;}

}

}

}

}

// function to  find shortest path between 2 routers

void find_path(int i,int j)

Department of Computer Science and EngineeringNetwork Lab CS602{

}

printf("%c",'A' + i);

if(i != j)

{

printf(" --> ");

find_path(routeTable[i][j].via,j);

}

// function to display  routing table for each router

void disp_route_table(int i)

{

int j;

printf("\nFinal Routing Table for %c: ",'A' + i);

printf("\n\tDestination\tCost\tOutgoing line");

printf("\n\t-------------\t----\t--------------\n");

for(j=0;j<n;j++)

{

printf("\n\t\t%c",'A' + j);

printf("\t%d",routeTable[i][j].cost);

printf("\t%c",'A' + routeTable[i][j].via);

printf("\n");

}

}

// function to read initial routing table for each router.

void read_route_table()

{

int i,j;

printf("Enter the initial routing table (if no direct node, enter 999):\n");for(i=0;i<n;i++)

{

printf("\nRouting table for %c:\n",'A' + i);

for(j=0;j<n;j++)

{

if(i==j)

routeTable[i][j].cost=0;

else

{

printf("--> %c:",'A' + j);

scanf("%d",&routeTable[i][j].cost);

}

if(routeTable[i][j].cost != INFINITY)

routeTable[i][j].via=j;

else

routeTable[i][j].via=INFINITY;

}

}

}

// main function

Department of Computer Science and EngineeringNetwork Lab CS602int main()

{

int src,dst,i;

int opt;

printf("Enter the Number of routers:");

scanf("%d",&n);

//read  initial routing table

read_route_table();

//build the routing table

for(i=0;i<n;i++)

build_route_table(i);

//display the final routing table

for(i=0;i<n;i++)

disp_route_table(i);

do

{

printf("\nEnter the Source node(0 to %d): ",n-1);

scanf("%d",&src);

printf("Enter the Destination node(0 to %d):",n-1);

scanf("%d",&dst);

if(src > (n - 1) || dst > (n - 1))

printf("\n router doest not exist");

else

{

}

find_path(src,dst);

printf("\nThe cost of the shortest route is:\t

%d\n",routeTable[src][dst].cost);

printf("\nDo you want to continue? (0/1):\n");

scanf("%d",&opt);

}while(opt);

return 0;

}

Experiment No. 4

Department of Computer Science and EngineeringNetwork Lab CS602Problem Statement:

Using TCP sockets, write a client-server program to make client sending the file name and theserver to send back the contents of the requested file if present.

Theory:

A socket allows an application to "plug in" to the network and communicate with other applicationsthat are also plugged in to the same network. Information written to the socket by an application onone machine can be read by an application on a different machine, and vice versa. Sockets come indifferent   flavors,   corresponding   to   different   underlying   protocol   families   and   different   stacks   ofprotocols within a family. we deal only with the TCP/IP protocol family. The main flavors of socketsin the TCP/IP family are stream sockets and datagram sockets. Stream sockets use TCP as the end-to-end protocol (with IP underneath) and thus provide a reliable byte-stream service. Datagram socketsuse UDP (again, with IP underneath) and thus provide a best-effort datagram service that applicationscan use to send individual messages up to about 65,500 bytes in length.

A socket using the TCP/IP protocol family is uniquely identified by an Internet address, an end-to-endprotocol (TCP or UDP), and a port number. When a socket is first created, it has an associated protocolbut no Internet address or port number. Until a socket is bound to a port number, it cannot receivemessages from a remote application.

Sockets, protocols, and ports.

Algorithm (Client Side)

![Im143](images/Im143)

Department of Computer Science and EngineeringNetwork Lab CS6021. Start.

2. Create a socket using socket () system call.

3. Connect the socket to the address of the server using connect () system call.

4. Send the filename of required file using send () system call.

5. Read the contents of the file sent by server by recv () system call.

6. Stop.

Algorithm (Server Side)

1. Start.

2. Create a socket using socket () system call.

3. Bind the socket to an address using bind () system call.

4. Listen to the connection using listen () system call.

5. Accept connection using accept ()

6. Receive filename and transfer contents of file with client.

7. Stop.

Client/Server communication using TCP socket:

/***************************************************************************  File Name   : tcpClient.c

![Im148](images/Im148)

*

*  Description : TCP Client program

***************************************************************************/Department of Computer Science and EngineeringNetwork Lab CS602#include<stdio.h>

#include<netdb.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<stdlib.h>

#include<string.h>

#define BUF_SIZE 500

#define PORT 3500

int main(int argc, char **argv)

{

int n,sd;

struct hostent *hp;

struct sockaddr_in server;

char *host, rbuf[BUF_SIZE], sbuf[BUF_SIZE];

if (argc==2)

host = argv[1];

else

{

}

fprintf(stderr, "usage: client  host\n");

exit(1);

/* translate host name into peer's IP address */

hp = gethostbyname(host);

if (!hp)

{

fprintf(stderr, "Client: unknown host: %s\n", host);

exit(1);

}

/* build address data structure */

bzero((char *)&server,sizeof(struct sockaddr_in));

bcopy(hp->h_addr,(char *)&server.sin_addr,hp->h_length);

server.sin_family=AF_INET;

server.sin_port=htons(PORT);

/* create client socket */

if ((sd = socket(AF_INET,SOCK_STREAM,0)) < 0)

{

perror("Client: socket Error");

exit(1);

}

if (connect(sd,(struct sockaddr *)&server,sizeof(server)) < 0)

{

perror("Client: connect Error");

close(sd);

exit(1);

}

printf("Enter the file name (type stop to close the SERVER) :\n");scanf("%s",sbuf);

Department of Computer Science and EngineeringNetwork Lab CS602write(sd,sbuf,BUF_SIZE);

printf("Content of the file: \n");

while(n=read(sd,rbuf,BUF_SIZE)>0)

printf("%s",rbuf);

close(sd);

return(0);

}

/***************************************************************************  File Name   : tcpServer.c

*

*  Description : Server program using tcp sockets to transfer the contents ofthe requested file

***************************************************************************/#include<stdio.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<string.h>

#include<stdlib.h>

#include<fcntl.h>

#define BUF_SIZE 500

#define PORT 3500

int main()

{

int fd;  // file descriptor

int sd,new_sd;  // socket descriptors

int   client_len;

struct sockaddr_in server,client;

char n,rbuf[BUF_SIZE],buf[BUF_SIZE]; // buffer variables

/* build address data structure */

bzero((char *)&server,sizeof(struct sockaddr_in));

server.sin_family=AF_INET;

server.sin_port=htons(PORT);

server.sin_addr.s_addr=htonl(INADDR_ANY);

/* create server socket  */

if ((sd = socket(AF_INET,SOCK_STREAM,0)) < 0)

{

perror("Server :  socket error");

exit(1);

}

if ((bind(sd,(struct sockaddr *)&server,sizeof(server))) < 0)

Department of Computer Science and EngineeringNetwork Lab CS602{

perror("Server : bind error");

exit(1);

}

// listen to the incoming connections

listen(sd,5);

while(1)

{

client_len=sizeof(client);

printf("Waiting for connection...\n");

if ((new_sd = accept(sd,(struct sockaddr *)&client,&client_len))< 0){

perror("Server : accept error");

exit(1);

}

printf("Connected...\n");

n=read(new_sd,buf,BUF_SIZE);

if(strcmp(buf,"stop") == 0)

{

printf("Server is closed");

break;

}

fd=open(buf,O_RDONLY);

if(fd == -1)

else

{

printf("File %s does not exists\n",buf);

while(n=read(fd,rbuf,BUF_SIZE)>0)

{

write(new_sd,rbuf,BUF_SIZE);

}

printf("File %s content sent...\n",buf);

}

close(new_sd);

close(fd);

}

close(sd);

return(0);

}

Problem Statement:

Experiment No. 5

Department of Computer Science and EngineeringNetwork Lab CS602Using UDP SOCKETS, write a client-server program to make the client sending two numbers and anoperator, and server responding with the result. Display the result and appropriate messages for invalidinputs at the client side.

Theory:   Refer to the Experiment No. 4

Algorithm (Client Side)

1. Start.

2. Create a socket using socket () system call.

3. Connect the socket to the address of the server using connect () system call.

4. Read two numbers and an operator, and them using sendto () system call.

5. Receive the result sent by server using recvfrom () system call.

6. Stop.

Algorithm (Server Side)

1. Start.

2. Create a socket using socket () system call.

3. Bind the socket to an address using bind () system call.

4. Listen to the connection using listen () system call.

5. Accept connection using accept ()

6. Receive the numbers and operator. Send the result to the client.

7. Stop.

Client/Server communication using TCP socket

/**************************************************************************![Im162](images/Im162)

Department of Computer Science and EngineeringNetwork Lab CS602*  File Name   : udpClient.c

*

*  Description : UDP Client

***************************************************************************/#include <stdio.h>

#include <stdio_ext.h>

#include <string.h>

#include <sys/time.h>

#include <netdb.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <stdlib.h>

#include  <string.h>

#define SERVER_UDP_PORT   5003  /* UDP port*/

#define MAXLEN       64      /* maximum data length */

int main(int argc, char **argv)

{

struct  hostent     *hp;

struct  sockaddr_in      server, client;

int     data_size = MAXLEN, port = SERVER_UDP_PORT;

int     sd, server_len;

char    *pname, *host, rbuf[MAXLEN], sbuf[MAXLEN],ch;int i, j;

int opt =1;

float n1,n2;

char op;

pname = argv[0];

argc--;

argv++;

if (argc > 0)

{

host = *argv;

if (--argc > 0)

}

else

{

port = atoi(*++argv);                   // port number//  must specify server address

fprintf(stderr,"Usage: %s [-s data_size] host [port]\n", pname);exit(1);

}

/* Create a datagram socket */

if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)

{

fprintf(stderr, "Can't create a socket\n");

exit(1);

Department of Computer Science and EngineeringNetwork Lab CS602}

/* Store server's information */

bzero((char *)&server, sizeof(server));

server.sin_family = AF_INET;

server.sin_port = htons(port);

if ((hp = gethostbyname(host)) == NULL)

{

fprintf(stderr,"Can't get server's IP address\n");

exit(1);

}

bcopy(hp->h_addr, (char *)&server.sin_addr,hp->h_length);

/* Bind local address to the socket */

bzero((char *)&client, sizeof(client));  // initalise client addressclient.sin_family = AF_INET;    // asign address family

client.sin_port = htons(0);

client.sin_addr.s_addr = htonl(INADDR_ANY); // assign any port

// assign port

if (bind(sd, (struct sockaddr *)&client,sizeof(client)) == -1)

{

fprintf(stderr, "Can't bind name to socket\n");

close(sd);

exit(1);

}

printf(" \n Connected to the server : ");

server_len = sizeof(server);

while(opt == 1)

{

printf("\n Enter operator(+,-,/,*):");

scanf("%c",&op);

printf("\n Enter first number:");

scanf("%f", &n1);

printf("\n Enter second number:");

scanf("%f", &n2);

sprintf (sbuf, "%f%c%f", n1,op, n2);

/* send the parameters */

if (sendto(sd, sbuf, data_size, 0, (struct sockaddr *)&server,server_len) == -1)

{

fprintf(stderr, "\n sendto error\n");

close(sd);

exit(1);

}

/* receive the result */

`

if (recvfrom(sd, rbuf, MAXLEN, 0, (struct sockaddr *) &server,&server_len) < 0)

{

fprintf(stderr, "\n recvfrom error\n");

exit(1);

close(sd);

Department of Computer Science and EngineeringNetwork Lab CS602}

}

printf("\n Result : %s", rbuf);

printf("\n Want to continue ? (0/1) :");

scanf("%d",&opt);

setbuf(stdin,NULL);

// clear  input streams

close(sd);

return(0);

}

/***************************************************************************  File Name   : udpServer.c

*

*  Description : UDP server to perform arithmetic operarion and send the result.***************************************************************************/#include <stdio.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#define SERVER_UDP_PORT   5003           /* Server port */

#define MAXLEN    64                  /* maximum data length */

int      sd, client_len, port, n;

char     buf[MAXLEN];                 /* buffer for storing  messages */struct   sockaddr_in server, client;

int  dv_flg=0;                        /* to check for division error */float n1,n2,res;

char op;

int main(int argc, char **argv)

{

switch(argc)

{

case 1:

port = SERVER_UDP_PORT;

break;

case 2:

port = atoi(argv[1]);

break;

default:

fprintf(stderr, "Usage: %s [port]\n", argv[0]);

exit(1);

}

/* Create a datagram socket */

if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)

{

exit(1);

fprintf(stderr, "Can't create a socket\n");

}

Department of Computer Science and EngineeringNetwork Lab CS602/* Bind an address to the socket */

bzero((char *)&server, sizeof(server));/* fill the structure with zeros*/server.sin_family = AF_INET;             /* assign address family */server.sin_port = htons(port);           /* assign port */

server.sin_addr.s_addr = htonl(INADDR_ANY);  /* any IP address */if (bind(sd, (struct sockaddr *)&server,sizeof(server)) == -1)

{

exit(1);

}

fprintf(stderr, "Can't bind name to socket\n");

close(sd);

printf("waiting .. .");

client_len = sizeof(client);

while (1)

{

dv_flg=0;

/* Recieve first number */

if ((n = recvfrom(sd, buf, MAXLEN, 0,(struct sockaddr *)&client,&client_len)) < 0)

{

fprintf(stderr, "Can't receive datagram\n");

close(sd);

exit(1);

}

/* Extract the parameters */

sscanf (buf,"%f%c%f",&n1,&op,&n2);

if(op == '+')

res = n1 + n2;

if(op == '-')

res = n1 - n2;

if(op == '*')

res = n1 * n2;

if(op == '/')

{

if (n2==0)

dv_flg =1;

else

res = n1 / n2;

}

if(dv_flg == 1)    /* division error */

strcpy(buf,"Divison error");

else

sprintf (buf, "%f", res);

if (sendto(sd, buf, n, 0,(struct sockaddr *)&client, client_len) < 0 )/* send datagram */

{

fprintf(stderr, "Can't send datagram\n");

close(sd);

exit(1);

}

Department of Computer Science and EngineeringNetwork Lab CS602}

close(sd);

return(0);

}

Experiment No. 6

Problem Statement:

Write a program for Hamming Code generation for error detection and correction

Theory:

Hamming codes (Richard Hamming, 1950) are used for detecting and correcting single bit errors intransmitted data. This requires that 3 parity bits (check bits) be transmitted with every 4 data bits. Thealgorithm is called A(7, 4) code, because it requires seven bits to encode 4 bits of data.Algorithm (encoding)

Index (k+ r) bits starting from 1.  E.g .  bit 1, 2, 3, 4, 5, etc.

1.

2. Write the bit position numbers in binary.  i.e.  1, 10, 11, 100, 101, etc.

3. All bit positions that are powers of two are parity bits.

4. All other bit positions are data bits.

5. Each data bit is included in a unique set of 2 or more parity bits, as determined by thebinary form of its bit position.

- Bit position

- Encoded data bits

p1

p2

d1

p4

d2

d3

d4

p8

d5

d6

d7

d8

d9

d10

d11

p16

d12

d13d14d15X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

X

XXX...XXX

X

XXp1

p2

p4

p8

p16

- Parity

- bit

- coverage

Algorithm (decoding)

Department of Computer Science and EngineeringNetwork Lab CS6021. To check for errors, check all of the parity bits. If all parity bits are correct, there is no error.2. Otherwise, the sum of the positions of the erroneous parity bits identifies the erroneous bit.3.

If only one parity bit indicates an error, the parity bit itself is in error. Erroneous parity bitmeans no. of one 1’s is odd.  Correct parity bit means no.  of one 1’s is even.

4. Extract the data bits if there is no error.

/***************************************************************************  File Name   : HamCode.c

*

*  Description : Hamming Code generation for error detection and correction.***************************************************************************/#include<stdio.h>

#define MAX_SZ  50

int data[MAX_SZ],temp[MAX_SZ];

// finds 2^n

int power(int n)

{

int i,p=1;

for(i=1;i<=n;i++)

{

p=p*2;

}

return(p);

}

// computes parity bits, k= no. of data bits,r=no. of parity bits.

int find_parity_bits(int k, int r)

{

int n,i,j;

int err_sum = 0,cnt_ones;

n = j = 1;

while(n < power(r))

{

i=n;

cnt_ones=0;

while(i<=(k+r))

{

for(j=0;j<n;j++)

{

if(temp[i+j]==1)

cnt_ones++;

}

i=i+2*n;

}

if((cnt_ones%2)!=0)

{

Department of Computer Science and EngineeringNetwork Lab CS602temp[n]=1;

err_sum += n ;

}

else

temp[n]=0;

n=n*2;

}

return err_sum;

}

//finds hamming code

int hamming_code(int k)

{

int i,j,d=0;

int r = 1; //r = no.of parity bits

while(k > (power(r)-r-1))

r++;

j = k;

for(i=1;i<=(k+r);i++)

{

if(i==power(d))

{

}

else

}

return(r);

}

temp[i]=0;

d++;

temp[i]=data[j--];

int  check_err(int err_pos,int r)

{

int i;

for(i=1;i < power(r) ; i = i * 2)

{

if(err_pos == i)

{

return 1;

}

}

return 0;

}

int main()

Department of Computer Science and EngineeringNetwork Lab CS602{

int k,r;

int err_pos,i;

printf("no of databits\n");

scanf("%d",&k);

printf("enter the data to be transmitted(0's & 1's)\n");

for(i=1;i<=k;i++)

scanf("%d",&data[i]);

r = hamming_code(k);   // find hamming code

printf ("\nNo. of parity bits r = %d",r);

find_parity_bits(k,r);

printf("\n\nHamming code for the data:\n");

for(i=1;i<=(k+r);i++)

printf("%4d",temp[i]);

// error detection and correction

printf("\n\nenter the recieved  data:\n");

for (i=1; i <= k+r; i++)

scanf("%d", &temp[i]);

err_pos =  find_parity_bits(k,r);

if (err_pos != 0)

{

if(check_err(err_pos,r))

printf("\n\nParity bit P%d  is corrupted, data is fine", err_pos);else

{

printf("\n\nData bit D%d is corrupted. ", err_pos);

// flip the error bit

temp[err_pos] = !(temp[err_pos]);

printf("\n\nCorrected data bits with new parity bits\n");for(i=1;i<=(k+r);i++)

printf("%4d",temp[i]);

}

else

}

printf("No error");

return 0;

}

Experiment No. 7

Problem Statement:

Write a program for simple RSA algorithm to encrypt and decrypt the data.

Department of Computer Science and EngineeringNetwork Lab CS602Theory:

The RSA algorithm is named after Ron Rivest, Adi Shamir and Len Adleman, who invented it in1977.The RSA algorithm can be used for both public key encryption and digital signatures. Its securityis based on the difficulty of factoring large integers.

Algorithm (computing public key and the private key)

1. Choose two large prime numbers, p and q

2. Compute n = p x q and z = (p - 1) x (q - 1).

3.

Choose a number that is  relatively prime to z and call it e

i.e.   gcd (z, e) =1

4.

Find d such that e x d = 1 mod z.

Public key = {e, n}    and     private key = {d, n}.

Algorithm (encryption and decryption)

Let P be plaintext (an Integer) to be encrypted, 0 ≤ P ≤n

1. To encrypt compute C = Pe (mod n)

2. To decrypt C, compute P = Cd (mod n).

RSA is based on the following key property:

Pde (mod n) = P (mod n)

Modular arithmetic involving large numbers can be simplified by using the following property.(ab) mod n = ((a mod n )(b mod n )) mod

Department of Computer Science and EngineeringNetwork Lab CS602/***************************************************************************  File Name   : RSA.c

*

*  Description :  Simple RSA algorithm to encrypt and decrypt the data.***************************************************************************/#include "stdafx.h"

#include<stdio.h>

#include<math.h>

#include<string.h>

#define MAX_SZ 100

unsigned int min(unsigned int  x, unsigned int y)

{

return(x<y?x:y);

}

unsigned int max(unsigned int x, unsigned int y)

{

return(x>y?x:y);

}

unsigned int gcd(unsigned int x, unsigned int y)

{

if(x==y)

return(x);

else

return(gcd(min(x,y),max(x,y)-min(x,y)));

}

unsigned int  xpowy_modn(unsigned int x,unsigned int  y, unsigned int n){

unsigned int r=1;

while(y>0)

{

if((int)(y%2)==1)

r=(r*x)%n;

x=(x*x)%n;

y=y/2;

}

return(r);

}

unsigned int find_encrypt_key(unsigned int z)

{

unsigned int e;

do

{

printf("\n Enter a number e that is  relatively prime to z and < z:");scanf("%d",&e);

if(e>=z)

Department of Computer Science and EngineeringNetwork Lab CS602}while(gcd(e,z)!=1);

continue;

return(e);

}

unsigned int find_decrypt_key(unsigned int e,unsigned int z)

{

unsigned int d;

for(d=2;d<z;++d)

{

if(((long int)(e*d)%(long int)z)==1)

break;

}

return(d);

}

int main()

{

//long double

unsigned int plain_txt[MAX_SZ], cipher_txt[MAX_SZ];

unsigned int p,q,z,n,e,d;

char msg[MAX_SZ];

int i;

read:

do

{

printf("\n Enter two large prime numbers p and q:");

scanf("%d%d",&p,&q);

}while(p==q);

n=p*q;

z=(p-1)*(q-1);

printf("\n n=%d,z=%d",n,z);

if(n < 120)

{

printf("\n\nPlease keep n >= 122");

goto read;

}

e=find_encrypt_key(z);

d=find_decrypt_key(e,z);

printf("\nPublic key ={%d,%d}",e,n);

printf("\nPrivate key ={%d,%d}",d,n);

printf("\nEnter a string consisting only letters(a-zA-Z) :");

scanf("%s", msg);

for(i=0;i<strlen(msg);i++)

{

plain_txt[i]=msg[i];

printf("\n%c = %d:",plain_txt[i],plain_txt[i]);

}

Department of Computer Science and EngineeringNetwork Lab CS602// find cipher text

printf("\n\nCipher Text:\n");

for(i=0; i<strlen(msg); i++)

{

cipher_txt[i] = xpowy_modn(plain_txt[i], e,n);

printf("\n%d=%c",cipher_txt[i],cipher_txt[i]);

}

printf("\n\nPlain Text:\n ");

for(i=0; i<strlen(msg); i++)

{

plain_txt[i] = xpowy_modn(cipher_txt[i],d,n);

printf("\n%c = %d",plain_txt[i],plain_txt[i]);

}

return(0);

}

Experiment No. 8

Problem Statement:

Write a program for congestion control using Leaky bucket algorithm.

Theory:

Leaky bucket (proposed by Jonathan S. Turner, 1986) is a traffic shaping   algorithm. Each hostis connected to the network by an interface containing a leaky bucket, that is, a finiteinternal queue. If a packet arrives at the queue when it is full, the packet is discarded. Inother   words,   if   one   or   more   process   are   already   queued,   the   new   packet   isunceremoniously discarded.

The host is allowed to put one packet per clock tick onto the network. This mechanismturns an uneven flow of packet from the user process inside the host into an even flow ofpacket onto the network, smoothing out bursts and greatly reducing the chances ofcongestion.

Algorithm

1. The leaky bucket consists of a finite queue.

2. When a packet arrives, if there is room on the queue it is appended to the queue; otherwise, it isdiscarded.

3. At every clock tick, one packet is transmitted

Department of Computer Science and EngineeringNetwork Lab CS602/***************************************************************************  File Name   : LeakyBucket.c

*

*  Description : A program to implement Leaky Bucket Algorithm

***************************************************************************/#include "stdafx.h"

#include<stdio.h>

#include<stdlib.h>

#define BUCKETSIZE 250

#define OUTRATE 25

struct

{

int arrtime;

int weight;

}packet[15];

void read_packets(int n)

{

int i;

for(i=0;i<n;i++)

{

printf("Enter arrival time:");

scanf("%d",&packet[i].arrtime);

printf("Enter the packet size:");

scanf("%d",&packet[i].weight);

}

}

// leaky bucket algorithm

void lky_buckNextet()

{

int excess=BUCKETSIZE;

int i,j=0,rem=0;

// receive packets for 30 msec

for(i=0;i<=30;i++)

{

if(packet[j].arrtime==i)

![Im203](images/Im203)

Department of Computer Science and EngineeringNetwork Lab CS602{

if(packet[j].weight<=excess)

{

rem=packet[j].weight+rem;

excess=excess-packet[j].weight;

printf("At time=%d: packet %d inserted into

bucket,",i,j+1);

printf(" remaining bucket size= %d\n",excess);j=j+1;

}

else

{

}

printf("At time = %d: packet %d discarded,",i,j+1);printf("Packet size is more than buffer size\n");j=j+1;

}

// send  packets every 5 msec

if((i%5)==0)

{

if(rem>=OUTRATE)

{

rem=rem-OUTRATE;

excess=excess+OUTRATE;

printf("At time = %d : 25 Kbytes are transfered ",i);printf("Free available space in the bucket=%d\n",excess);}

else if(rem>0)

{

excess=excess+rem;

printf("At time = %d : %d Kbytes are transferred",i,rem);

{

printf("Free available space in the bucket=%d\n",excess);rem=0;

}

}

}//for

// Empty the bucket

while(rem != 0)

if(rem < OUTRATE)

{

excess=excess+rem;

printf("At time = %d : %d Kbytes are transfered ",i++,rem);printf("Free available space in the bucket=%d\n",excess);break;

}

rem=rem-OUTRATE;

excess=excess +  OUTRATE;

printf("At time = %d : %d Kbytes are transfered ",i++,OUTRATE);printf("Free available space in the bucket=%d\n",excess);

}

printf("Bucket is empty");

}

Department of Computer Science and EngineeringNetwork Lab CS602int main()

{

int n;

printf("Enter the number of packets:");

scanf("%d",&n);

read_packets(n);

lky_bucket();

return 0;

}

