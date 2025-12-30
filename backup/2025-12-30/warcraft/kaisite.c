// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("避水金晴售[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "白鹿蒼狼的坐騎[2;37;0m
它是白鹿蒼狼的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kaisite");
        set("owner_name", "白鹿蒼狼");
        set_temp("owner", "kaisite");
        set_temp("owner_name", "白鹿蒼狼");
        ::setup();
}
