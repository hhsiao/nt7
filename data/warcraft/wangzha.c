// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("誰殺了我[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "我又殺了誰[2;37;0m
它是王詐的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wangzha");
        set("owner_name", "王詐");
        set_temp("owner", "wangzha");
        set_temp("owner_name", "王詐");
        ::setup();
}
