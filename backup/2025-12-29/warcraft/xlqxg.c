// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m母鹿[2;37;0m[2;37;0m", ({"qiaoba"}));        
        set("gender", "女性");                
        set("long", "哈哈哈哈[2;37;0m
它是喬巴的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xlqxg");
        set("owner_name", "喬巴");
        set_temp("owner", "xlqxg");
        set_temp("owner_name", "喬巴");
        ::setup();
}
