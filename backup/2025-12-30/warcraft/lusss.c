// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m女神[2;37;0m[2;37;0m", ({"kaokao"}));        
        set("gender", "女性");                
        set("long", "超級誘人的女神[2;37;0m
它是畫別緻的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lusss");
        set("owner_name", "畫別緻");
        set_temp("owner", "lusss");
        set_temp("owner_name", "畫別緻");
        ::setup();
}
