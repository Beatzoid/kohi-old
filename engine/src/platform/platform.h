#pragma once

#include "defines.h"

typedef struct platform_state {
    void* internal_state;
} platform_state;

/**
 * @brief Startup the current platform
 *
 * @param plat_state The platform state
 * @param application_name The application name (for windowed OS's)
 * @param x
 * @param y
 * @param width
 * @param height
 * @return TRUE if it succeeded, FALSE otherwise
 */
KAPI b8 platform_startup(
    platform_state* plat_state,
    const char* application_name,
    i32 x,
    i32 y,
    i32 width,
    i32 height);

/**
 * @brief Shutdown the platform
 *
 * @param plat_state The platform state
 */
KAPI void platform_shutdown(platform_state* plat_state);

KAPI b8 platform_pump_messages(platform_state* plat_state);

/**
 * @brief Allocate memory for the specific platform
 *
 * @param size The size to allocate
 * @param aligned
 */
void* platform_allocate(u64 size, b8 aligned);

/**
 * @brief Free memory for the specific platform
 *
 * @param block The block to free
 * @param aligned
 */
void platform_free(void* block, b8 aligned);

/**
 * @brief Zero memory for the specific platform
 *
 * @param block The block to free
 * @param aligned
 */
void* platform_zero_memory(void* block, u64 size);

/**
 * @brief Copy memory for the specific platform
 *
 * @param dest The memory destination
 * @param source The memory source
 * @param size The size
 */
void* platform_copy_memory(void* dest, const void* source, u64 size);

/**
 * @brief Set memory for the specific platform
 *
 * @param size The destination to set
 * @param value The value to set
 * @param size The size of the value
 */
void* platform_set_memory(void* dest, i32 value, u64 size);

/**
 * @brief Write a message to the platform console
 *
 * @param message The message to write
 * @param color The color
 */
void platform_console_write(const char* message, u8 color);

/**
 * @brief Write an error message to the platform console
 *
 * @param message The error message to write
 * @param color The color
 */
void platform_console_write_error(const char* message, u8 color);

/**
 * @brief Gets the absolute time of the platform
 */
f64 platform_get_absolute_time();

/**
 * @brief Sleep on the thread for the provided ms, blocking the main thread
 *
 * @details This should only be used for giving time back to the OS for unused update power, and therefore it is not exported
 *
 * @param ms The time in milliseconds to sleep for
 */
void platform_sleep(u64 ms);
