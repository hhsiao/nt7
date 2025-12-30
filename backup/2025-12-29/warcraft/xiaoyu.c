// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m嘯天犬[2;37;0m[2;37;0m", ({"jingquan"}));        
        set("gender", "男性");                
        set("long", "嘯天犬[2;37;0m
它是江小魚的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaoyu");
        set("owner_name", "江小魚");
        set_temp("owner", "xiaoyu");
        set_temp("owner_name", "江小魚");
        ::setup();
}
