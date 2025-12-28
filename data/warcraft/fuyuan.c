// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "一個睡袋，江湖人士用來在野外睡覺用的。[2;37;0m
它是星雲鎖鏈的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fuyuan");
        set("owner_name", "星雲鎖鏈");
        set_temp("owner", "fuyuan");
        set_temp("owner_name", "星雲鎖鏈");
        ::setup();
}
