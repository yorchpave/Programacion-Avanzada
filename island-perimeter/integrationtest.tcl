#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Put your test case here

# 2x2
eval spawn [lrange $argv 0 end]

expect "Size of row: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
#expect "What is the id:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "Size of col: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "island 0:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0,1\r"
expect "island 1:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1,1\r"
expect "Perimeter = 8" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

# 3x2
eval spawn [lrange $argv 0 end]
expect "Size of row: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "Size of col: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "island 0:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1,1\r"
expect "island 1:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1,1\r"
expect "island 2:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1,1\r"
expect "Perimeter = 10" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

# Error 2x1
eval spawn [lrange $argv 0 end]
expect "Size of row: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "Size of col: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "island 0:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1,1\r"
expect "Invalid row!" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}




