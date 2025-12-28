// This program is a part of NT MudLIB

#include <ansi.h>
#include <combat.h>

inherit NPC;

void smart_fight();
string do_flee();

void create()   
{
        object weapon;

        set_name("趙飛柳", ({ "zhao feiliu","boss","zhao"}) );
        set("gender", "男性" );
        set("nickname",BLU"閻王傘"NOR);
        set("title","血雨門");
        set("class","legend");
        set("age",77);
        set("start_room", "/d/city/dongmen");

        set("long","一個青衣白髮的老人，一個人獨行在山道間，手裡撐著柄油紙傘。嘴角帶
著絲神秘而詭譎的微笑，天上烏雲密佈，細雨紛紛，滴滴落在老人手上的
油紙傘上。\n");

        set("gender", "男性" );
        set("agi",70);
        set("gold",30);
        set("real_boss",1);
        set("boss",1);  // immune to some rascal skill and ghostcurse.
                                                // busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 71000000000); // L110
        set_temp("apply/armor",8000);
        
        set_skill("force", 4000);
        set_skill("taixuan-gong",4000);
        set_skill("dodge", 4000);
        set_skill("lingbo-weibu",4000);
        set_skill("unarmed", 4000);
        set_skill("luohan-quan",4000);
        set_skill("parry", 4000);       

        map_skill("force", "taixuan-gong");
        map_skill("dodge", "lingbo-weibu");
        map_skill("unarmed", "luohan-quan");    // 想打落我武器的就來吧..
                
        set("max_qi",90000000000);
        set("max_jing",70000000000);
        
        setup();

        weapon=new("/clone/weapon/sword");
        weapon->set_name(YEL"油紙傘"NOR, ({ "umbrella" }) );
        set("long","油紙傘(Umbrella)。\n",weapon);
        set("value",0,weapon);
        weapon->wield();

        weapon=new("/clone/cloth/cloth");
        weapon->set_name(CYN"血雨青衣"NOR, ({ "cloth" }) );
        set("long","血雨青衣(Cloth)。\n", weapon);
        set("value",0,weapon);
        weapon->wear();
                
        set("drop/fixed_amount",1);
        set("drop/fixed_drop", ({               // L80-90 books

        }));
                
        set("drop/bg",0);
        set("drop/common",100);
        set("drop/rare",0);     
        set("drop/amount",3);
        set("drop/common_drop",({

        }) );
        set("drop/rare_drop",({

        }) );
        
}

void die()
{
        object who = query_max_damage_from();
        object lotus;
        
        if (random(2)) {
                //lotus = new(AREA_XINJIANG"obj/lotus");
                //if (lotus) lotus->move(this_object());
        }

        if (!objectp(who))
                who = query_temp("last_damage_from");
                
        if (objectp(who))
               BUFF_D->generate_drop_item(this_object(),who);

        ::die();
        return;
}

void smart_fight()
{
        object ob;
        mapping data, buff;
        object target,*enemy;
        int f,i;
        
        enemy=query_enemy();
        
        if (!random(3))
        {
                for (i=0;i<sizeof(enemy);i++) {
                        if (objectp(ob = enemy[i])) {
                                if (BUFF_D->check_buff(ob,"lowresist"))        continue;
                                message_vision(BCYN WHT"\n破世陰雩\n"NOR,this_object());
                                message_vision(HIB"\n趙飛柳的傘突然一收，滿天的黑雲聚起，忽然間一聲霹靂，"NOR,this_object());   
                                message_vision(HIB"閃電自雲層擊下，照亮了陰翳的天際。\n"NOR,this_object());
                                data =
                                        ([
                                                "reduce_damage" : -20,
                                        ]);
                                buff =
                                        ([
                                                "caster":this_object(),
                                                "target":ob,
                                                "name":"天魔無相·破世陰雩",
                                                "type": "lowresist",
                                                "attr": "curse",
                                                "buff_data" : data,
                                                "time":60,
                                                "buff_msg":HIB"$N"HIB"心頭劇振，眼前一陣眩暈。\n"NOR,
                                        ]);
                                BUFF_D->buffup(buff);
                                break;
                        }
                }       
        }
                
        if (!random(3))
        {
                for (i=0;i<sizeof(enemy);i++) {
                        if (objectp(ob = enemy[i])) {
                                if (BUFF_D->check_buff(ob,"cursedflesh"))      continue;
                                message_vision(BBLU HIW"\n空魂異血\n"NOR,this_object());
                                data =
                                        ([
                                                "defense" : -2000,
                                        ]);
                                buff =
                                ([
                                        "caster":this_object(),
                                        "target":  ob,
                                        "type": "cursedflesh",
                                        "attr":  "curse",
                                        "name": "破邪心經·空魂異血",
                                        "time": 30,
                                        "buff_msg":HIC"\n$n"HIC"面上浮現出青藍之色，噴出一團腥臭的煙氣。\n"HIB"$N"HIB"猝不及防，吸進一口毒霧，登時搖搖欲墜．．．\n\n"NOR,
                                ]);
                                BUFF_D->buffup(buff);
                                break;
                        }
                }       
        }

        target = select_opponent();
        add_temp("apply/attack",25000);
        add_temp("apply/damage",400000000);
        add_temp("apply/unarmed_damage",400000000);
        message_vision(BRED WHT"\n傷痕措手\n"NOR,this_object());
        message_vision(HIB"趙大先生的傘一撐，人影已如鬼魅般貼近$n，五指向$n背上抓去！"NOR,"抓傷！"HIR"$n的背上被抓得鮮血淋漓．．．\n"NOR, this_object());
        COMBAT_D->do_attack(this_object(),target,0,3);
        COMBAT_D->do_attack(this_object(),target,0,3);
        COMBAT_D->do_attack(this_object(),target,0,3);
        add_temp("apply/attack",-25000);
        add_temp("apply/damage",-400000000);
        add_temp("apply/unarmed_damage",-400000000);
        
        if (!BUFF_D->check_buff(target,"armorup"))
        {
                data =
                        ([
                                "armor" : -10000,
                        ]);
                buff =
                        ([
                                "caster":this_object(),
                                "target":target,
                                "name":"天魔無相·傷痕措手",
                                "type": "armorup",
                                "attr": "curse",
                                "buff_data" : data,
                                "time":   60,
                                "buff_msg":" "NOR,
                        ]);
                        BUFF_D->buffup(buff);
        }

        return;
}


mixed valid_damage(object victim,object attacker,int damage)
{
        mapping data = ([]);
        object thr;
        if (!thr = query_temp("weapon", attacker))
                return 0;

        data["msg"] = CYN"趙飛柳手裡的油紙傘風車般旋轉起來，突然間已化成一道光圈。\n只聽叮、叮、叮一連串急響，"+thr->name()+CYN"已在一瞬間被震飛。\n"NOR;
        data["damage"] = -damage;
        return data;
}

