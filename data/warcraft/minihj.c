// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m小花貓[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "我的寵物[2;37;0m
它是胡古月的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "minihj");
        set("owner_name", "胡古月");
        set_temp("owner", "minihj");
        set_temp("owner_name", "胡古月");
        ::setup();
}
