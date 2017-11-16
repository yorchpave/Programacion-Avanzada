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
eval spawn [lrange $argv 0 end]

expect "Value of n: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Fizz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

eval spawn [lrange $argv 0 end]

expect "Value of n: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "15\r"
expect "1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Fizz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Buzz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Fizz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "7" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "8" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Fizz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Buzz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "11" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Fizz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "13" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "14" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "FizzBuzz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
