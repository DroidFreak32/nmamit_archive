set ns [new Simulator]

# Open new file for NAMTRACE
set nf [open 001.nam w]
$ns namtrace-all $nf

# Open new file for LOGTRACE
set tf [open 001.tr w]
$ns trace-all $tf

# Body of the finish procedure
proc finish {} {
	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf
	exec nam 001.nam &
	exit 0
}

# Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

# Create links between nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 512Kb 10ms DropTail

$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n1 $n2 orient right

# Set the queue limit - default is 50 packets
$ns queue-limit $n0 $n1 50
$ns queue-limit $n1 $n2 50

# Create transport agent
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set null0 [new Agent/Null]
$ns attach-agent $n2 $null0
$ns connect $udp0 $null0

# Create application to generate traffic
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

# Start and stop traffic
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run