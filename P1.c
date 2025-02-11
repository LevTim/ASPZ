#include <stdio.h>
#include <stdbool.h>

// Перелічуваний тип для місяців
typedef enum {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE,
    JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
} Month;

// Перелічуваний тип для календарів
typedef enum {
    GREGORIAN,
    JULIAN
} Calendar;

// Функція для перевірки високосного року
int is_leap_year(int year, Calendar cal) {
    if (cal == GREGORIAN) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    } else { // JULIAN
        return (year % 4 == 0);
    }
}

// Функція для перевірки коректності введення дати
bool is_valid_date(int day, Month month, int year, Calendar cal) {
    int days_in_month;
    switch (month) {
        case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
            days_in_month = 30;
            break;
        case JANUARY: case MARCH: case MAY: case JULY:
        case AUGUST: case OCTOBER: case DECEMBER:
            days_in_month = 31;
            break;
        case FEBRUARY:
            days_in_month = is_leap_year(year, cal) ? 29 : 28;
            break;
        default:
            return false;  // Невірний місяць
    }

    return (day >= 1 && day <= days_in_month);
}

// Функція для обчислення завтрашньої дати
void next_day(int day, Month month, int year, Calendar cal) {
    int days_in_month;
    switch (month) {
        case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
            days_in_month = 30;
            break;
        case JANUARY: case MARCH: case MAY: case JULY:
        case AUGUST: case OCTOBER: case DECEMBER:
            days_in_month = 31;
            break;
        case FEBRUARY:
            days_in_month = is_leap_year(year, cal) ? 29 : 28;
            break;
    }

    // Перевірка переходу на наступний день
    if (day < days_in_month) {
        day++;
    } else {
        day = 1;
        if (month == DECEMBER) {
            month = JANUARY;
            year++;
        } else {
            month++;
        }
    }

    if (cal == JULIAN) {
        // Для юліанського календаря віднімаємо 13 днів
        if (day <= 13) {
            day += 18;  // Для коректного переходу до попереднього місяця (враховуємо відставання)
            if (month == JANUARY) {
                month = DECEMBER;
                year--;
            } else {
                month--;
            }
        } else {
            day -= 13;  // Віднімаємо 13 днів
        }
        
        printf("Next date (calendar Julian): %02d-%02d-%d\n", day, month, year);
        return;  // Виходимо з функції після виведення для юліанського календаря
    }

    printf("Next date (calendar Gregorian): %02d-%02d-%d\n", day, month, year);
}

int main() {
    int day, month, year;
    
    while (1) {  // Запускаємо нескінченний цикл до коректного введення
        printf("Enter date (DD MM YYYY): ");
        if (scanf("%d %d %d", &day, &month, &year) != 3) {
            printf("Invalid input format. Please enter numbers in the format DD MM YYYY.\n");
            while (getchar() != '\n');  // Очищаємо буфер введення
            continue;
        }

        if (month < 1 || month > 12) {
            printf("Invalid month. Please enter a month between 1 and 12.\n");
            continue;
        }

        if (!is_valid_date(day, (Month)month, year, GREGORIAN)) {
            printf("Invalid day for the given month and year. Please try again.\n");
            continue;
        }

        break;  // Якщо всі перевірки пройдено, виходимо з циклу
    }

    next_day(day, (Month)month, year, GREGORIAN);  // Для григоріанського календаря
    next_day(day, (Month)month, year, JULIAN);    // Для юліанського календаря
    
    return 0;
}
