set ns [new Simulator]

# Open new file for NAMTRACE
set nf [open 002.nam w]
$ns namtrace-all $nf

# Open new file for LOGTRACE
set tf [open 002.tr w]
$ns trace-all $tf

# Body of the finish procedure
	proc finish {} {
	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf
	exec nam 002.nam &
	exit 0
}

# Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# Create links between nodes
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail

# Set the queue limit - default is 50 packets
$ns queue-limit $n0 $n2 50
$ns queue-limit $n1 $n2 50
$ns queue-limit $n2 $n3 50

# Create TCP agent between node 0 & 3
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0

# Create FTP applicaton for TCP agent
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
Agent/TCP set packetSize_ 1000

# Create UDP agent b/w node 1 & 3 agent
set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0
set null0 [new Agent/Null]
$ns attach-agent $n3 $null0
$ns connect $udp0 $null0

# Create CBR application to generate traffic for UDP Agent
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

# Start and stop traffic
$ns at 0.75 "$ftp0 start"
$ns at 4.75 "$ftp0 stop"
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run