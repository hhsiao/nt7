// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m斯萊普尼斯[2;37;0m[2;37;0m", ({"sleipnir"}));        
        set("gender", "男性");                
        set("long", "一匹毛白勝雪，有八隻腳的神駿天馬，奧丁騎著它環遊世界。[2;37;0m
它是奧丁的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "odin");
        set("owner_name", "奧丁");
        set_temp("owner", "odin");
        set_temp("owner_name", "奧丁");
        ::setup();
}
