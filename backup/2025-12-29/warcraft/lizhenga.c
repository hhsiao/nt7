// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m真愛一龍[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "女性");                
        set("long", "我唉我的龍龍[2;37;0m
它是李一爭的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lizhenga");
        set("owner_name", "李一爭");
        set_temp("owner", "lizhenga");
        set_temp("owner_name", "李一爭");
        ::setup();
}
