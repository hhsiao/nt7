// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "小白虎[2;37;0m
它是葉紅魚的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hongy");
        set("owner_name", "葉紅魚");
        set_temp("owner", "hongy");
        set_temp("owner_name", "葉紅魚");
        ::setup();
}
