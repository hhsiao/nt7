// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "這是美眉斗轉家養的朱雀。[2;37;0m
它是美眉斗轉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mrmm");
        set("owner_name", "美眉斗轉");
        set_temp("owner", "mrmm");
        set_temp("owner_name", "美眉斗轉");
        ::setup();
}
