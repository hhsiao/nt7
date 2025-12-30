// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m利維坦貝希摩[2;37;0m[2;37;0m", ({"leviathan"}));        
        set("gender", "男性");                
        set("long", "哈利路亞！！！！！！！！！！！[2;37;0m
它是鑲鑲鑲鑲的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "sipilu");
        set("owner_name", "鑲鑲鑲鑲");
        set_temp("owner", "sipilu");
        set_temp("owner_name", "鑲鑲鑲鑲");
        ::setup();
}
