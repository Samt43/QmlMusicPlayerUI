function formatDurationToString(duration) {

    var d2 = new Date(duration * 1000);
    var H = "";
    var M = "";
    var S ="";

    if(d2.getUTCHours()!=0)
    { H = d2.getUTCHours() +":" }

    if (d2.getMinutes()<10)
    {
        M = "0"
    }
    M = M+d2.getMinutes()

    if (d2.getSeconds()<10)
    {
        S = "0"
    }
    S = S+d2.getSeconds()

    return  H + M + ":" + S
}
