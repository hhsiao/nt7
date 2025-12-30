// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m心堅[2;37;0m[2;37;0m", ({"xinjian"}));        
        set("gender", "男性");                
        set("long", "一隻天賦異稟卻有殘疾的烏龜[2;37;0m
它是鄭和的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "zhenghe");
        set("owner_name", "鄭和");
        set_temp("owner", "zhenghe");
        set_temp("owner_name", "鄭和");
        ::setup();
}
