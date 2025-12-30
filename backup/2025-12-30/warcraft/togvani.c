// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[34m窮奇熊[2;37;0m[2;37;0m", ({"gaze"}));        
        set("gender", "男性");                
        set("long", "桶桶[2;37;0m
它是李彬彬的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "togvani");
        set("owner_name", "李彬彬");
        set_temp("owner", "togvani");
        set_temp("owner_name", "李彬彬");
        ::setup();
}
