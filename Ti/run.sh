#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 2000 ]; then
    echo "[ Error |@UnixeID(Yeye)]"
    exit 1
fi
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -I /sdcard/Ti/git.png -S bigtext -t '♨️ Thermal Injack' 'Tag' "$sor" > /dev/null 2>&1
}
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. Thermal Injack.... "
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Point                    :  2.0"
    echo "       - Release               :  07 - Mar - 2025"
    echo "       - Name Shell         :  Thermal Injack"
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority Thermal Injeck. "
    sleep 2
    echo
 Joystik() {
    if [ "$1" = "-g" ]; then
        /data/local/tmp/thermal -g
    elif [ "$1" = "-b" ]; then
        /data/local/tmp/thermal -b
    elif [ "$1" = "-l" ]; then
        /data/local/tmp/thermal -l
    elif [ "$1" = "-w" ]; then
        /data/local/tmp/thermal -w
    elif [ "$1" = "-d" ]; then
        /data/local/tmp/thermal -d
    elif [ "$1" = "-h" ]; then
       /data/local/tmp/thermal -h
    else
        printf "Usage Josytik [-g|-b|-l|-w|-h]\n"
    fi
}
source="$(getprop ro.build.version.release)"
ver_num=$(( ${source%%.*} ))  # Konversi ke angka
if [ "$ver_num" -le 13 ]; then
    printf "\n"
    printf "\t ID       : Versi Android Anda Support\n"
    printf "                 dengan Shell Script C ini \n"
    printf "                 Versi Android Anda : $source\n"
    printf "\n"
    printf "\t US      : Your Android Version Supports\n"
    printf "                 with this C Shell Script \n"
    printf "                 Your Android Version : $source\n"
    printf "\n"
        cp /sdcard/Ti/thermal /data/local/tmp
        chmod +x /data/local/tmp/thermal
    Joystik "$@"
    shell "Wait Loading Thermal Inject Min 1-3"
else
    printf "\t ID     : Versi Android Anda Tidak Mendukung\n"
    printf "               Shell Script C ini\n"
    printf "               Versi Android Anda : $source\n"
    printf "\n"
    printf "\t US    : Your Android Version Does Not Support\n"
    printf "               This C Shell Script \n"
    printf "               Your Android Version : $source\n"
    printf "\n"
    echo "Shell Script C Not Support Android : $source"
fi