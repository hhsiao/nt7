// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m天長[1;32m地久[2;37;0m[2;37;0m", ({"forever"}));        
        set("gender", "男性");                
        set("long", "如果你是我的傳說 讓他天長地久 追夢的人 為你在等候 [2;37;0m
它是浪漫傳說的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "romance");
        set("owner_name", "浪漫傳說");
        set_temp("owner", "romance");
        set_temp("owner_name", "浪漫傳說");
        ::setup();
}
