// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是禮炮三響的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lpy");
        set("owner_name", "禮炮三響");
        set_temp("owner", "lpy");
        set_temp("owner_name", "禮炮三響");
        ::setup();
}
