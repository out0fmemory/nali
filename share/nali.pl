while ($line=<>) {
    $line =~ s/((?:[0-2]?[0-9]{1,2}\.){3}[0-2]?[0-9]{1,2})/qqwry($1)/eg;
    print $line;
}
sub qqwry {
    my $lang=$ENV{'LANG'};
    my $ip=$_[0];

    #my $iconv=`which iconv`;
    #if (index($iconv,"iconv")<0) {
    #    $iconv=`whereis iconv`;
    #}

    if ($lang=~m/\.([A-z0-9\-_]+)/) {
        $lang=$1
    } else {
        $lang="UTF-8"
    }

    my $addr;
    $addr=`qqwrynali $ip|iconv -f GBK -t $lang`;

    #if (index($iconv,"iconv")<0) {
    #    $addr=`qqwrynali $ip`;
    #} else {
    #    $iconv=~s/\n//g;
    #    $addr=`qqwrynali $ip|$iconv -f GBK -t $lang`;
    #}
    $addr =~ s/\n//g;
    return "$ip\[$addr\]";
}
