// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m吳裕蘭[2;37;0m[2;37;0m", ({"yulan"}));        
        set("gender", "女性");                
        set("long", "乳頭很大，胸部很挺，陰毛厚而密[2;37;0m
它是張居正的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "nandi");
        set("owner_name", "張居正");
        set_temp("owner", "nandi");
        set_temp("owner_name", "張居正");
        ::setup();
}
