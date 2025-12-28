// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("筋斗雲[2;37;0m[2;37;0m", ({"jdy"}));        
        set("gender", "男性");                
        set("long", "筋斗雲[2;37;0m
它是浪漫滿屋的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "skyamh");
        set("owner_name", "浪漫滿屋");
        set_temp("owner", "skyamh");
        set_temp("owner_name", "浪漫滿屋");
        ::setup();
}
