// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuq"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是歐陽美眉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ouyangmm");
        set("owner_name", "歐陽美眉");
        set_temp("owner", "ouyangmm");
        set_temp("owner_name", "歐陽美眉");
        ::setup();
}
