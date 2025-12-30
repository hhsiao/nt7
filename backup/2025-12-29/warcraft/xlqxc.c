// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大河馬[2;37;0m[2;37;0m", ({"xlqxca"}));        
        set("gender", "女性");                
        set("long", "醜就是醜[2;37;0m
它是烏索普的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xlqxc");
        set("owner_name", "烏索普");
        set_temp("owner", "xlqxc");
        set_temp("owner_name", "烏索普");
        ::setup();
}
