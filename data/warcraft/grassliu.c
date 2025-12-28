// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("愛華[2;37;0m[2;37;0m", ({"lhua"}));        
        set("gender", "女性");                
        set("long", "花[2;37;0m
它是吖藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "grassliu");
        set("owner_name", "吖藥");
        set_temp("owner", "grassliu");
        set_temp("owner_name", "吖藥");
        ::setup();
}
