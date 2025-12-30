// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是菜飛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "caif");
        set("owner_name", "菜飛");
        set_temp("owner", "caif");
        set_temp("owner_name", "菜飛");
        ::setup();
}
