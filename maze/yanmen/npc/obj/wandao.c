// gangdao.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW"蒙古彎刀"NOR, ({ "wan dao","blade" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "這是一柄亮晃晃的鋼刀，是蒙古官兵的常備武器。\n");
                set("value", 1000);
                set("rigidity",200);
                set("no_get",1);
                set("no_put",1);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回刀鞘。\n");
        }
        init_blade(400);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       object weapon=this_object();
       int dam;

       if( weapon->query("equipped"))
       {
        dam = me->query_temp("jun_quest/group") 
              * weapon->query("weapon_prop/damage")/10;
        dam = dam/4+random(dam/3);

        if( dam < 40 )
          message_vision(
          BLINK+HIM"$N的左翼遭到攻擊，損失了部分軍隊！\n"NOR,victim);
        else if( dam < 80 )
          message_vision(
              BLINK+HIM"$N的右翼遭到伏擊，損失慘重！！\n"NOR,victim);
        else if( dam < 120 )
          message_vision(
          BLINK+HIM"$N的中軍遭到埋伏，損失殆盡！！\n"NOR,victim);
        else  
          message_vision(
          BLINK+HIM"$N的全軍陷入了敵軍的埋伏，存亡已在旦夕！！\n"NOR,victim);  

        victim->receive_damage("qi",dam,me);
        victim->receive_wound("qi",dam,me); 
       }
       return 0;
}

void owner_is_killed() { destruct(this_object()); }  

