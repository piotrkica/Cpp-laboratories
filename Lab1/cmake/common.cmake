function(zip_all_work)
    get_filename_component(directoryBasename ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    get_filename_component(directory2Zip "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
    set(archiveFullPath ${PROJECT_BINARY_DIR}/${directoryBasename}.zip)

    message("Creating ZIP from path: ${directory2Zip} into ${archiveFullPath}")
    file(ARCHIVE_CREATE OUTPUT ${archiveFullPath}
        PATHS ${directory2Zip}
        FORMAT zip
#        VERBOSE
    )
endfunction()


function(add_subdirectory_if_exists directory_to_add)
    if (IS_DIRECTORY "${directory_to_add}")
            add_subdirectory(${directory_to_add})
    endif ()
endfunction()


function(generate_pdf_if_possible cpp_sources)
    find_program(enscriptTool enscript)
    find_program(ps2pdfTool ps2pdf)
    if (enscriptTool AND ps2pdfTool)
        add_custom_target(pdf
            COMMAND cat ${cpp_sources} | enscript -Ecpp --color=1 -C  -fCourier8 -o - | ps2pdf - pdf.pdf
            DEPENDS ${PROJECT_NAME}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )
    endif()
endfunction()
