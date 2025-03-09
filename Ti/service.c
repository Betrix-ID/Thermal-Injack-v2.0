#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define SCRIPT_VERSION "2.0"

void shell(const char *pesan) {
    char command[512];
    snprintf(command, sizeof(command),
             "cmd notification post -I /sdcard/Ti/git.png -S bigtext -t '♨️ Thermal Injack' 'Tag' '%s' > /dev/null 2>&1",
             pesan);
    system(command);
}

// Fungsi untuk mode Gaming (Performa Maksimal)
void mode_gaming() {
    printf("⚡ Gaming Mode: Performance Boosting ⚡\n");
    system("cmd thermalservice override-status 0");  // Disable thermal throttling
    system("cmd activity  idle-maintenance > /dev/null 2>&1");
    system("cmd activity memory-factor set CRITICAL"); // Maksimalkan memory usage
    system("settings put global activity_manager_constants power_check_interval=1200000,power_check_max_cpu_1=0,power_check_max_cpu_2=0,power_check_max_cpu_3=0,power_check_max_cpu_4=0,full_pss_lowered_interval=0,full_pss_min_interval=0,service_usage_interaction_time=0,service_usage_interaction_time_post_s=0,usage_stats_interaction_interval=0,usage_stats_interaction_interval_post_s=0");
    system("cmd device_config put connectivity_thermal_power_manager apply_action_time_seconds 100000");
    system("cmd device_config put connectivity_thermal_power_manager wifi_disconnected_time_seconds 180000");
    system("cmd device_config put connectivity_thermal_power_manager criteria_4_lte_pref_mode 1"); // Prioritaskan LTE
    system("cmd device_config put connectivity_thermal_power_manager apply_1_enabled false"); // Jangan turunkan performa meskipun panas
    system("ionice -t -c1 -n0 cmd activity set-watch-heap --user 0 52000000 com.android.systemui --init.svc.thermal-engine=stopped --init.svc.thermal-hal-1-0=stopped --init.svc.thermalservice=false");
    printf("🔥 Gaming Mode Activated!\n");
    system("cmd package compile -m everything -f com.android.systemui");
    shell("High Thermal Inject");
}

// Fungsi untuk mode Balanced (Seimbang antara performa dan daya)
void mode_balanced() {
    printf("⚖️ Balanced Mode: Optimized Performance ⚖️\n");
    system("cmd thermalservice override-status 1");  // Aktifkan thermal throttling ringan
    system("cmd activity memory-factor set MODERATE"); // Gunakan memory dalam batas wajar
    system("settings put global activity_manager_constants power_check_interval=3000000,power_check_max_cpu_1=2,power_check_max_cpu_2=2,power_check_max_cpu_3=1,power_check_max_cpu_4=1,full_pss_lowered_interval=600000,full_pss_min_interval=600000,service_usage_interaction_time=1000,service_usage_interaction_time_post_s=1000,usage_stats_interaction_interval=1000,usage_stats_interaction_interval_post_s=1000");
    system("cmd device_config put connectivity_thermal_power_manager apply_action_time_seconds 200000");
    system("cmd device_config put connectivity_thermal_power_manager wifi_disconnected_time_seconds 300000");
    system("cmd device_config put connectivity_thermal_power_manager criteria_4_lte_pref_mode 0"); // Tidak terlalu memprioritaskan LTE
    system("cmd device_config put connectivity_thermal_power_manager apply_1_enabled true"); // Aktifkan pengelolaan suhu
    system("ionice -t -c1 -n0 cmd activity set-watch-heap --user 0 16000000 com.android.systemui --init.svc.thermal-engine=stopped --init.svc.thermal-hal-1-0=stopped --init.svc.thermalservice=false");
    printf("🍃 Balanced Mode Activated!\n");
    system("cmd package compile -m speed -f com.android.systemui");
    shell("Balanced Thermal Inject");
}

// Fungsi untuk mode Low Power (Hemat Baterai)
void mode_low_power() {
    printf("🔋 Low Power Mode: Battery Saving 🔋\n");
    system("cmd thermalservice override-status 2");  // Batasi performa untuk hemat daya
    system("cmd activity memory-factor set LOW"); // Gunakan memory seirit mungkin
    system("settings put global activity_manager_constants power_check_interval=6000000,power_check_max_cpu_1=1,power_check_max_cpu_2=1,power_check_max_cpu_3=0,power_check_max_cpu_4=0,full_pss_lowered_interval=1200000,full_pss_min_interval=1200000,service_usage_interaction_time=5000,service_usage_interaction_time_post_s=5000,usage_stats_interaction_interval=5000,usage_stats_interaction_interval_post_s=5000");
    system("cmd device_config put connectivity_thermal_power_manager apply_action_time_seconds 300000");
    system("cmd device_config put connectivity_thermal_power_manager wifi_disconnected_time_seconds 600000");
    system("cmd device_config put connectivity_thermal_power_manager criteria_4_lte_pref_mode 0"); // Tidak memprioritaskan LTE
    system("cmd device_config put connectivity_thermal_power_manager apply_1_enabled true"); // Aktifkan thermal management
    system("ionice -t -c1 -n0 cmd activity set-watch-heap --user 0 100000 com.android.systemui --init.svc.thermal-engine=stopped --init.svc.thermal-hal-1-0=stopped --init.svc.thermalservice=false");
    printf("💡 Low Power Mode Activated!\n");
    system("cmd package compile -m verify -f com.android.systemui");
    shell("Lwo Thermal Inject");
}

void Delete_script() {
    system("cmd thermalservice override-status reset");  // Batasi performa untuk hemat daya
    system("cmd activity memory-factor set NORMAL"); // Gunakan memory seirit mungkin
    system("settings delete global activity_manager_constants > /dev/null 2>&1" );
    system("cmd device_config put connectivity_thermal_power_manager apply_action_time_seconds 100");
    system("cmd device_config put connectivity_thermal_power_manager wifi_disconnected_time_seconds 1800");
    system("cmd device_config put connectivity_thermal_power_manager criteria_4_lte_pref_mode 0"); // Tidak memprioritaskan LTE
    system("cmd device_config delete connectivity_thermal_power_manager apply_1_enabled > /dev/null 2>&1 "); 
    system("ionice -t -c1 -n0 cmd activity set-watch-heap --user 0 0 com.android.systemui --init.svc.thermal-engine=stopped --init.svc.thermal-hal-1-0=stopped --init.svc.thermalservice=false");
    printf("Succes delete To script Thermal Injeck");
    system("cmd package compile -m verify -f com.android.systemui");
    shell("Succes delete To script Thermal Injeck");
}

void WARNING() {
    printf("\n⚠️ WARNING: Use Script Thermal Inject\n\n");
    printf("1. Battery wasteful\n");
    printf("2. The phone will heat up quickly\n");
    printf("3. Increase RAM usage\n");
    printf("4. Improving resource utilization\n\n");
    shell("Help To notes WARNING script");
}

void usage() {
    printf("\nThermal Inject v%s - Performance & Power Management\n", SCRIPT_VERSION);
    printf("Enhance system performance, balance, or save battery\n\n");
    printf("Usage: thermal_inject [OPTIONS]\n\n");
    printf("Options:\n");
    printf("  -g  Enable Gaming Mode (Performance Boost)\n");
    printf("  -b  Enable Balanced Mode (Optimal Performance & Power)\n");
    printf("  -l   Enable Low Power Mode (Battery Saving)\n");
    printf(" -d.  Delete Configuration script Thermal Injeck\n");
    printf("  -w  Show this notes warning\n");
    printf("  -h  Show this help message\n\n");
    printf("⚠ WARNING: Use Gaming Mode carefully, as it may cause overheating!\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
       usage();
    }

for (int i = 1; i < argc; ++i) {  
     if (strcmp(argv[i], "-g") == 0) {  
        sleep(3);
        mode_gaming();  
    } else if (strcmp(argv[i], "-b") == 0) { 
        sleep(3);
        mode_balanced();  
    } else if (strcmp(argv[i], "-l") == 0) { 
        sleep(3);             
        mode_low_power();  
    } else if (strcmp(argv[i], "-d") == 0) {
         sleep(3);
        Delete_script();
    } else if (strcmp(argv[i], "-w") == 0) {
      sleep(1);              
        WARNING();  
    } else if (strcmp(argv[i], "-h") == 0) {  
      sleep(2);
        usage();  
    } else {  
        printf("Unknown option: %s\n", argv[i]);  
        usage();  
    }  
}

    sleep(1);

    printf("\n");
    printf("\n");
    printf(" ⚠️ Module ini dilindungi oleh hak cipta dan hanya\n");
    printf(" dapat digunakan oleh pengguna biasa. Penggunaan ini\n");
    printf(" tidak diperbolehkan untuk pengembang lain, termasuk\n");
    printf(" penggunaan kode, desain, atau fitur lain dalam module\n");
    printf(" tanpa izin tertulis dari pemilik hak cipta module.\n");
    printf("______________________________________________(+)\n\n");
    return 0;
}