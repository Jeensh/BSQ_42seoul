# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    map_maker.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:41:00 by donghshi          #+#    #+#              #
#    Updated: 2022/02/20 09:52:32 by donghshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}
