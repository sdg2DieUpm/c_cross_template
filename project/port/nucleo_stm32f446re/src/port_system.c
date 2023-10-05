#include "port_system.h"
#include "stm32f4xx_hal.h" //  ROMAN dejaría el import aqui escondido

/**
 * @brief System Clock Configuration
 *
 * This function should not be accesible from the outside to avoid configuration problems.
 * This function starts a system timer that generates a SysTick every 1 ms.
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    while (1)
      ;
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    while (1)
      ;
  }
}

size_t port_system_init()
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  return 0;
}


uint32_t port_system_get_millis()
{
  return HAL_GetTick(); /* ms */
}

void port_system_delay_ms(uint32_t ms)
{
  uint32_t tickstart = port_system_get_millis();

  while((port_system_get_millis() - tickstart) < ms)
  {
  }
}

void port_system_delay_until_ms(uint32_t *t, uint32_t ms)
{
  uint32_t until = *t + ms;
  uint32_t now = port_system_get_millis();
  if (until > now) {
    port_system_delay_ms(until - now);
  }
  *t = port_system_get_millis();
}

// TODO: esta llamada debe sustituirse, la hace HAL_Init. Estaba en stm32f4xx_hal_msp.c
/**
 * Initializes the Global MSP.
 */
void HAL_MspInit(void)
{

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);
}

//------------------------------------------------------
// SUBRUTINAS DE ATENCION A LAS INTERRUPCION
//------------------------------------------------------
/**
 * @brief This function handles System tick timer.
 */
// TODO: sustituir por funcion propia
void SysTick_Handler(void)
{
  HAL_IncTick();
}
