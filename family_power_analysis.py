#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
NT7 MUD Family Power Curve Analysis
Based on combatd.c combat formulas and family skill systems

This script calculates and visualizes the power curves for each martial arts
family (門派) in the NT7 MUD based on the combat daemon formulas.
"""

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
from matplotlib import rcParams
import json

# Configure matplotlib for Chinese characters
# Try to find a suitable Chinese font
chinese_fonts = ['Microsoft YaHei', 'SimHei', 'STHeiti', 'AR PL UMing TW', 'WenQuanYi Micro Hei']
font_found = False
for font_name in chinese_fonts:
    try:
        font = fm.FontProperties(family=font_name)
        rcParams['font.sans-serif'] = [font_name]
        rcParams['axes.unicode_minus'] = False
        font_found = True
        print(f"Using font: {font_name}")
        break
    except:
        continue

if not font_found:
    print("Warning: No Chinese font found. Chinese characters may not display correctly.")

# Family data from familyd.c and skill mapping
FAMILIES = {
    "shaolin": {
        "name": "少林寺",
        "fame": 10000000,
        "force": ["yijin-jing", "buddhism"],
        "unarmed": ["longzhua-gong", "jingang-quan", "qianye-shou", "luohan-quan"],
        "weapon": ["shaolin-zhang", "weituo-chu", "riyue-bian", "weituo-gun"],
        "dodge": ["shaolin-shenfa"],
        "parry": ["shaolin-zhang"],
        "special": ["jingang-zhao"]  # 金剛罩
    },
    "wudang": {
        "name": "武當派",
        "fame": 8000000,
        "force": ["taiji-shengong", "taoism"],
        "unarmed": ["taiji-quan"],
        "weapon": ["taiji-jian"],
        "dodge": ["tiyunzong"],
        "parry": ["taiji-jian"],
        "special": ["tianwei-zhengqi"]  # 天威正氣
    },
    "gaibang": {
        "name": "丐幫",
        "fame": 7000000,
        "force": ["huntian-qigong"],
        "unarmed": ["xianglong-zhang"],
        "weapon": ["dagou-bang"],
        "dodge": ["xiaoyaoyou"],
        "parry": ["dagou-bang"],
        "special": []
    },
    "quanzhen": {
        "name": "全真教",
        "fame": 5000000,
        "force": ["xiantian-gong"],
        "unarmed": ["kongming-quan"],
        "weapon": ["quanzhen-jian"],
        "dodge": ["jinyan-gong"],
        "parry": ["quanzhen-jian"],
        "special": []
    },
    "huashan": {
        "name": "華山派",
        "fame": 4500000,
        "force": ["zixia-shengong"],
        "unarmed": ["hunyuan-zhang"],
        "weapon": ["huashan-sword"],
        "dodge": ["feiyan-zoubi"],
        "parry": ["huashan-sword"],
        "special": ["jianyi"]  # 劍意
    },
    "duan": {
        "name": "段氏皇族",
        "fame": 4000000,
        "force": ["kurong-changong"],
        "unarmed": ["yiyang-zhi"],
        "weapon": [],
        "dodge": ["bafang-bu"],
        "parry": ["yiyang-zhi"],
        "special": ["qigong"]  # 氣功
    },
    "murong": {
        "name": "慕容世家",
        "fame": 4000000,
        "force": ["shenyuan-gong"],
        "unarmed": ["douzhuan-xingyi"],
        "weapon": ["murong-jian"],
        "dodge": ["lingbo-weibu"],
        "parry": ["douzhuan-xingyi"],
        "special": []
    },
    "xueshan": {
        "name": "雪山寺",
        "fame": 3500000,
        "force": ["longxiang-gong"],
        "unarmed": ["dashou-yin"],
        "weapon": ["jingang-chu", "xiangmo-chu"],
        "dodge": ["longxiang-gong"],
        "parry": ["jingang-chu"],
        "special": []
    },
    "lingjiu": {
        "name": "靈鷲宮",
        "fame": 3500000,
        "force": ["bahuang-gong"],
        "unarmed": ["liuyang-zhang"],
        "weapon": [],
        "dodge": ["yueying-wu"],
        "parry": ["liuyang-zhang"],
        "special": []
    },
    "emei": {
        "name": "峨嵋派",
        "fame": 3000000,
        "force": ["linji-zhuang"],
        "unarmed": ["jinding-mianzhang"],
        "weapon": ["huifeng-jian"],
        "dodge": ["zhutian-bu"],
        "parry": ["huifeng-jian"],
        "special": ["jingxin"]  # 靜心
    },
    "taohua": {
        "name": "桃花島",
        "fame": 2500000,
        "force": ["bihai-chaosheng"],
        "unarmed": ["tanzhi-shentong", "xuanfeng-leg"],
        "weapon": ["yuxiao-jian", "luoying-zhang"],
        "dodge": ["suibo-zhutian"],
        "parry": ["yuxiao-jian"],
        "special": ["qimen-xuanshu"]  # 奇門玄術
    },
    "shenlong": {
        "name": "神龍教",
        "fame": 2000000,
        "force": ["shenlong-xinfa"],
        "unarmed": ["huagu-mianzhang"],
        "weapon": ["shedao-qigong"],
        "dodge": ["youlong-shenfa"],
        "parry": ["shedao-qigong"],
        "special": []
    },
    "gumu": {
        "name": "古墓派",
        "fame": 1500000,
        "force": ["yunv-xinfa"],
        "unarmed": ["meinv-quan", "tianluo-diwang"],
        "weapon": ["yunv-jian", "yinsuo-jinling"],
        "dodge": ["yunv-shenfa"],
        "parry": ["yunv-jian"],
        "special": []
    },
    "xingxiu": {
        "name": "星宿派",
        "fame": 1200000,
        "force": ["huagong-dafa"],
        "unarmed": ["sanyin-zhua"],
        "weapon": [],
        "dodge": ["zhaixing-shu"],
        "parry": ["sanyin-zhua"],
        "special": ["poison"]  # 毒功
    },
    "xiaoyao": {
        "name": "逍遙派",
        "fame": 1000000,
        "force": ["beiming-shengong"],
        "unarmed": ["zhemei-shou"],
        "weapon": [],
        "dodge": ["lingbo-weibu"],
        "parry": ["zhemei-shou"],
        "special": ["xiaoyao-you"]  # 逍遙遊
    },
    "xuedao": {
        "name": "血刀門",
        "fame": 800000,
        "force": ["xuehai-mogong"],
        "unarmed": [],
        "weapon": ["xuedao-daofa"],
        "dodge": ["shenkong-xing"],
        "parry": ["xuedao-daofa"],
        "special": ["xueying-dafa"]  # 血影大法
    },
    "jianzong": {
        "name": "華山劍宗",
        "fame": 600000,
        "force": ["kuangfeng-jian"],
        "unarmed": [],
        "weapon": ["dugu-jiujian", "lonely-sword"],
        "dodge": ["feiyan-zoubi"],
        "parry": ["dugu-jiujian"],
        "special": ["jianyi"]  # 劍意
    },
    "ouyang": {
        "name": "歐陽世家",
        "fame": 500000,
        "force": ["hamagong"],
        "unarmed": ["hamagong"],
        "weapon": [],
        "dodge": ["chanchu-bufa"],
        "parry": ["hamagong"],
        "special": []
    },
    "hu": {
        "name": "關外胡家",
        "fame": 400000,
        "force": ["bingxin-jue"],
        "unarmed": ["kongming-quan"],
        "weapon": ["hu-blade"],
        "dodge": ["xiaoyaoyou"],
        "parry": ["hu-blade"],
        "special": []
    },
    "tangmen": {
        "name": "唐門世家",
        "fame": 650000,
        "force": ["bibo-shengong"],
        "unarmed": [],
        "weapon": ["qiulong-bian", "hand-blade"],
        "dodge": ["yufeng-xiang"],
        "parry": ["qiulong-bian"],
        "special": ["poison", "anqi"]  # 毒功、暗器
    },
    "mojiao": {
        "name": "魔教",
        "fame": 700000,
        "force": ["shenghuo-shengong"],
        "unarmed": ["sanfen-jiandao"],
        "weapon": ["shenghuo-ling"],
        "dodge": ["lingxu-bu"],
        "parry": ["shenghuo-ling"],
        "special": []
    }
}


class CombatCalculator:
    """
    Combat power calculator based on combatd.c formulas

    Key formulas from combatd.c:
    1. skill_power() - Base power calculation
    2. attack_value() - Attack power (AP)
    3. defend_value() - Defense power (DP)
    4. attack_damage() - Damage calculation
    """

    def __init__(self):
        self.EXP_LIMIT = 1000000000000  # 1 trillion

    def valid_power(self, combat_exp, reborn_times=0):
        """
        Calculate valid power from combat exp
        From combatd.c:550-564
        """
        if combat_exp > self.EXP_LIMIT:
            combat_exp = self.EXP_LIMIT

        if reborn_times >= 1:
            combat_exp += 50000000000 // 2
        if reborn_times >= 2:
            combat_exp += 100000000000 // 2
        if reborn_times >= 3:
            combat_exp += 500000000000 // 2

        return combat_exp // 1000 // 100

    def famsk_buff(self, family_id, skill_level, usage="attack"):
        """
        Calculate family skill buff
        From combatd.c:566-677
        """
        ratio = 0

        # 逍遙遊 (Xiaoyao special skill)
        if family_id == "xiaoyao":
            xiaoyao_you = skill_level
            percent = xiaoyao_you // 100
            if ratio < percent:
                ratio = percent

        # Specific martial skill bonuses
        if usage == "attack":
            # 劍意 (Jianyi - Sword Intent for Huashan/Jianzong)
            if family_id in ["huashan", "jianzong"]:
                jianyi = skill_level
                percent = jianyi // 50
                if ratio < percent:
                    ratio = percent

            # 天威正氣 (Tianwei Zhengqi for Wudang)
            elif family_id == "wudang":
                tianwei = skill_level
                percent = tianwei // 50
                if ratio < percent:
                    ratio = percent

            # 血影大法 (Xueying Dafa for Xuedao)
            elif family_id == "xuedao":
                xueying = skill_level
                percent = xueying // 50
                if ratio < percent:
                    ratio = percent

            # 奇門玄術 (Qimen Xuanshu for Taohua)
            elif family_id == "taohua":
                qimen = skill_level
                percent = qimen // 50
                if ratio < percent:
                    ratio = percent

            # 靜心 (Jingxin for Emei)
            elif family_id == "emei":
                jingxin = skill_level
                percent = jingxin // 50
                if ratio < percent:
                    ratio = percent

        if ratio >= 100:
            ratio = 100

        return ratio

    def skill_power(self, skill_level, combat_exp, strength=30, dexterity=30,
                    usage="attack", family_id=None, reborn_times=0, yuanshen_level=0):
        """
        Calculate skill power
        From combatd.c:679-738

        Formula:
        power = (level/10 * level/10 * level / 10000)
        power = power / 30 * attribute  (str for attack, dex for defense)
        power = power / 2 + valid_power(combat_exp) / 2
        power += power * famsk_buff / 100
        power += power * yuanshen_level / 100
        """
        if skill_level < 1:
            power = self.valid_power(combat_exp, reborn_times) / 2
            if usage == "attack":
                power = power / 30 * strength
            else:
                power = power / 30 * dexterity
            return power

        # Base power calculation
        power = skill_level / 10 * skill_level / 10 * skill_level / 10000

        # Attribute modifier
        if usage == "attack":
            power = power / 30 * strength
        else:
            power = power / 30 * dexterity

        # Combat exp bonus
        power = power / 2 + self.valid_power(combat_exp, reborn_times) / 2

        # Family skill buff
        if family_id:
            ratio = self.famsk_buff(family_id, skill_level, usage)
            power += power * ratio / 100

        # Yuanshen (元神) bonus
        if yuanshen_level > 0:
            power += power * yuanshen_level / 100

        return power

    def attack_value(self, skill_level, combat_exp, strength=30, family_id=None,
                     reborn_times=0, yuanshen_level=0):
        """
        Calculate attack power (AP)
        From combatd.c:2148-2180
        """
        attack = self.skill_power(skill_level, combat_exp, strength, 30,
                                 "attack", family_id, reborn_times, yuanshen_level)

        # Buff bonus (simplified, assuming level * buff = skill_level * 0)
        # attack += skill_level * buff

        return int(attack)

    def defend_value(self, skill_level, combat_exp, dexterity=30, family_id=None,
                     reborn_times=0, yuanshen_level=0):
        """
        Calculate defense power (DP for dodge/parry)
        From combatd.c:2186-2216
        """
        defend = self.skill_power(skill_level, combat_exp, 30, dexterity,
                                 "defense", family_id, reborn_times, yuanshen_level)

        return int(defend)

    def damage_calculation(self, skill_level, combat_exp, strength=30, jiali=0,
                          family_id=None, reborn_times=0, yuanshen_level=0):
        """
        Calculate base damage
        From combatd.c:895-948

        damage = skill_level + jiali + damage/10*strength
        damage += action["damage"] * damage / 100  (assume 100% bonus)
        """
        damage = skill_level
        damage += jiali
        damage += damage / 10 * strength

        # Assume 100% damage bonus from action
        damage += damage * 100 / 100

        # Yuanshen bonus
        if yuanshen_level > 0:
            damage += damage * yuanshen_level / 100

        return int(damage)

    def calculate_power_metrics(self, family_id, skill_level, combat_exp,
                                strength=30, dexterity=30, reborn_times=0,
                                yuanshen_level=0):
        """
        Calculate all power metrics for a family at a given skill level
        """
        family = FAMILIES[family_id]

        # Attack Power (AP)
        ap = self.attack_value(skill_level, combat_exp, strength, family_id,
                              reborn_times, yuanshen_level)

        # Defense Power (DP - dodge)
        dp_dodge = self.defend_value(skill_level, combat_exp, dexterity, family_id,
                                     reborn_times, yuanshen_level)

        # Defense Power (PP - parry)
        pp_parry = self.defend_value(skill_level, combat_exp, dexterity, family_id,
                                     reborn_times, yuanshen_level)

        # Damage
        jiali = skill_level // 2  # Assume jiali scales with skill
        damage = self.damage_calculation(skill_level, combat_exp, strength, jiali,
                                        family_id, reborn_times, yuanshen_level)

        # Combined power score (weighted average)
        power_score = (ap * 0.35 + dp_dodge * 0.25 + pp_parry * 0.25 + damage * 0.15)

        return {
            "attack_power": ap,
            "dodge_power": dp_dodge,
            "parry_power": pp_parry,
            "damage": damage,
            "power_score": power_score
        }


def generate_power_curves():
    """
    Generate power curves for all families across skill levels
    """
    calc = CombatCalculator()

    # Skill level range
    skill_levels = np.arange(0, 501, 5)

    # Different combat exp levels to test
    exp_levels = {
        "新手": 100000,          # 10萬
        "初級": 1000000,         # 100萬
        "中級": 10000000,        # 1000萬
        "高級": 100000000,       # 1億
        "大師": 1000000000,      # 10億
        "宗師": 10000000000,     # 100億
    }

    results = {}

    for family_id, family_data in FAMILIES.items():
        family_name = family_data["name"]
        results[family_id] = {
            "name": family_name,
            "fame": family_data["fame"],
            "curves": {}
        }

        for exp_name, exp_value in exp_levels.items():
            metrics_over_levels = []

            for skill_level in skill_levels:
                metrics = calc.calculate_power_metrics(
                    family_id, skill_level, exp_value,
                    strength=35, dexterity=35
                )
                metrics_over_levels.append(metrics)

            results[family_id]["curves"][exp_name] = metrics_over_levels

    return results, skill_levels, exp_levels


def plot_family_power_curves(results, skill_levels, exp_levels):
    """
    Create comprehensive power curve visualizations
    """
    # 1. Overall Power Score Comparison (Master Level)
    fig1, ax1 = plt.subplots(figsize=(16, 10))

    exp_name = "宗師"  # Master level
    for family_id, family_data in results.items():
        family_name = family_data["name"]
        power_scores = [m["power_score"] for m in family_data["curves"][exp_name]]
        ax1.plot(skill_levels, power_scores, label=family_name, linewidth=2, alpha=0.8)

    ax1.set_xlabel('技能等級 (Skill Level)', fontsize=14)
    ax1.set_ylabel('綜合戰力 (Power Score)', fontsize=14)
    ax1.set_title('各門派戰力曲線比較 (宗師級經驗)', fontsize=16, fontweight='bold')
    ax1.legend(loc='best', fontsize=10, ncol=3)
    ax1.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('family_power_comparison_master.png', dpi=300, bbox_inches='tight')
    print("Saved: family_power_comparison_master.png")

    # 2. Multi-panel: AP, DP, Damage for each family
    top_families = sorted(FAMILIES.items(), key=lambda x: x[1]["fame"], reverse=True)[:9]

    fig2, axes = plt.subplots(3, 3, figsize=(20, 16))
    fig2.suptitle('各門派戰力細項分析 (宗師級)', fontsize=18, fontweight='bold')

    for idx, (family_id, family_info) in enumerate(top_families):
        row = idx // 3
        col = idx % 3
        ax = axes[row, col]

        family_name = family_info["name"]
        curves = results[family_id]["curves"][exp_name]

        ap_values = [m["attack_power"] for m in curves]
        dp_values = [m["dodge_power"] for m in curves]
        damage_values = [m["damage"] for m in curves]

        ax.plot(skill_levels, ap_values, 'r-', label='攻擊力 (AP)', linewidth=2)
        ax.plot(skill_levels, dp_values, 'b-', label='閃避 (DP)', linewidth=2)
        ax.plot(skill_levels, damage_values, 'g-', label='傷害 (Damage)', linewidth=2)

        ax.set_title(f'{family_name}', fontsize=14, fontweight='bold')
        ax.set_xlabel('技能等級', fontsize=10)
        ax.set_ylabel('數值', fontsize=10)
        ax.legend(fontsize=9)
        ax.grid(True, alpha=0.3)

    plt.tight_layout()
    plt.savefig('family_power_details_top9.png', dpi=300, bbox_inches='tight')
    print("Saved: family_power_details_top9.png")

    # 3. Experience Level Comparison for selected families
    selected_families = ["shaolin", "wudang", "gaibang", "xiaoyao", "xuedao"]

    fig3, axes = plt.subplots(2, 3, figsize=(18, 12))
    fig3.suptitle('不同經驗等級的戰力成長曲線', fontsize=16, fontweight='bold')

    for idx, family_id in enumerate(selected_families):
        row = idx // 3
        col = idx % 3
        ax = axes[row, col]

        family_name = FAMILIES[family_id]["name"]

        for exp_name in exp_levels.keys():
            power_scores = [m["power_score"] for m in results[family_id]["curves"][exp_name]]
            ax.plot(skill_levels, power_scores, label=exp_name, linewidth=2, alpha=0.7)

        ax.set_title(f'{family_name}', fontsize=13, fontweight='bold')
        ax.set_xlabel('技能等級', fontsize=10)
        ax.set_ylabel('綜合戰力', fontsize=10)
        ax.legend(fontsize=9, loc='upper left')
        ax.grid(True, alpha=0.3)

    # Remove the extra subplot
    fig3.delaxes(axes[1, 2])

    plt.tight_layout()
    plt.savefig('family_power_by_exp_level.png', dpi=300, bbox_inches='tight')
    print("Saved: family_power_by_exp_level.png")

    # 4. Top 5 Families Ranking
    fig4, ax4 = plt.subplots(figsize=(14, 10))

    # Calculate average power score at level 500 (master level)
    family_rankings = []
    for family_id, family_data in results.items():
        final_power = family_data["curves"][exp_name][-1]["power_score"]
        family_rankings.append((family_data["name"], final_power, family_id))

    family_rankings.sort(key=lambda x: x[1], reverse=True)
    top_5 = family_rankings[:5]

    for family_name, _, family_id in top_5:
        power_scores = [m["power_score"] for m in results[family_id]["curves"][exp_name]]
        ax4.plot(skill_levels, power_scores, label=family_name, linewidth=3, alpha=0.9)

    ax4.set_xlabel('技能等級 (Skill Level)', fontsize=14)
    ax4.set_ylabel('綜合戰力 (Power Score)', fontsize=14)
    ax4.set_title('前五強門派戰力對比', fontsize=16, fontweight='bold')
    ax4.legend(loc='upper left', fontsize=12)
    ax4.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('top5_families_comparison.png', dpi=300, bbox_inches='tight')
    print("Saved: top5_families_comparison.png")

    # Print rankings
    print("\n=== 門派戰力排名 (技能500級) ===")
    for rank, (family_name, power, family_id) in enumerate(family_rankings, 1):
        print(f"{rank:2d}. {family_name:12s}: {power:10.0f}")

    plt.show()


def export_data_to_json(results, skill_levels):
    """
    Export power curve data to JSON for further analysis
    """
    export_data = {
        "skill_levels": skill_levels.tolist(),
        "families": {}
    }

    for family_id, family_data in results.items():
        export_data["families"][family_id] = {
            "name": family_data["name"],
            "fame": family_data["fame"],
            "curves": {}
        }

        for exp_name, curve_data in family_data["curves"].items():
            export_data["families"][family_id]["curves"][exp_name] = [
                {k: float(v) if isinstance(v, (int, float, np.integer, np.floating)) else v
                 for k, v in metrics.items()}
                for metrics in curve_data
            ]

    with open('family_power_data.json', 'w', encoding='utf-8') as f:
        json.dump(export_data, f, ensure_ascii=False, indent=2)

    print("Exported power data to: family_power_data.json")


def main():
    """
    Main execution function
    """
    print("NT7 MUD Family Power Curve Analysis")
    print("=" * 60)
    print(f"Analyzing {len(FAMILIES)} martial arts families...")
    print()

    # Generate power curves
    print("Generating power curves...")
    results, skill_levels, exp_levels = generate_power_curves()
    print(f"✓ Generated curves for skill levels 0-500")
    print(f"✓ Analyzed {len(exp_levels)} experience levels")
    print()

    # Create visualizations
    print("Creating visualizations...")
    plot_family_power_curves(results, skill_levels, exp_levels)
    print()

    # Export data
    print("Exporting data...")
    export_data_to_json(results, skill_levels)
    print()

    print("Analysis complete!")
    print("=" * 60)


if __name__ == "__main__":
    main()
